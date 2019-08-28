#ifndef OTUS_SIMPLETREE_H
#define OTUS_SIMPLETREE_H

#include <iostream>
#include <functional>
#include <memory>

namespace otus { namespace data {

  template <typename T> struct TreeNode {
        T*           data  = nullptr;
        TreeNode<T>* left  = nullptr;
        TreeNode<T>* right = nullptr;

        size_t size;

        bool is_root;

        TreeNode() : data(nullptr), left(nullptr), right(nullptr), size(0), is_root(true) {}
        TreeNode(const T& data) : data(new T(data)), left(nullptr), right(nullptr), size(0), is_root(false) {}

        ~TreeNode() {

            if (left)
                delete left;

            if (right)
                delete right;

            if (data)
                delete data;
        }

        void _make_left(const T& node) {
            if (left == nullptr) {
                left = new TreeNode<T>(node);
            } else {
                left->append(node);
            }
        }

        void _make_right(const T& node) {
            if (right == nullptr) {
                right = new TreeNode<T>(node);
            } else {
                right->append(node);
            }
        }

        void append(const T& node) {
            size++;
            if (data != nullptr) {
                if (*data >= node) {
                    _make_left(node);
                } else {
                    _make_right(node);
                }
            } else {
                data = new T(node);
            }
        }

        void call_cb(std::function<void(const T&)> cb, bool reverse = false) {
            if (reverse) {
                if (right)
                    right->call_cb(cb, reverse);
                if (data)
                    cb(*data);
                if (left)
                    left->call_cb(cb, reverse);
            } else {
                if (left)
                    left->call_cb(cb, reverse);
                if (data)
                    cb(*data);
                if (right)
                    right->call_cb(cb, reverse);
            }
        }
    };

template <typename NodeType, typename Allocator = std::allocator<TreeNode<NodeType>>> class SimpleTree {
private:
    TreeNode<NodeType>* _root;

public:
    SimpleTree() { _root = new TreeNode<NodeType>(); }
    ~SimpleTree() { delete _root; }
    void   append(const NodeType& data) { _root->append(data); }
    void   call_cb(std::function<void(const NodeType&)> cb, bool reverse = false) { _root->call_cb(cb, reverse); }
    size_t get_size() const { return _root->size; }
};

}} // namespace pirates::helpers

#endif // SIMPLETREE_H
