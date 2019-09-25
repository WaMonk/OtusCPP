#ifndef OTUS_SIMPLETREE_H
#define OTUS_SIMPLETREE_H

#include <iostream>
#include <functional>
#include <memory>

namespace otus { namespace data {

template <typename T> struct TreeNode {

    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(const T& member) {
        data = member;
        left = nullptr;
        right = nullptr;
    }

    void append(TreeNode<T>* node){
        if(data >= node->data){
            if(left == nullptr){
                left = node;
            }else{
                left->append(node);
            }
        }
        else{
            if(right == nullptr){
                right = node;    
            }else{
                right->append(node);
            }
        }
    }
};

template <typename NodeType, typename Allocator = std::allocator<TreeNode<NodeType>>> class SimpleTree {
using NodeTypeCB = std::function<void(const NodeType&)>;
private:
    TreeNode<NodeType>* _root;
    Allocator* _alloc;

    TreeNode<NodeType>* _make_node(const NodeType& data) {
        TreeNode<NodeType>* retval = _alloc->allocate(1);
        _alloc->construct(retval, data);
        return retval;
    }

    void _destroy_node(TreeNode<NodeType>* node){
        if(node->left != nullptr)
            _destroy_node(node->left);
        if(node->left != nullptr)
            _destroy_node(node->left);

        _alloc->destroy(node);
        _alloc->deallocate(node, 1);    
    }

    void _walk(TreeNode<NodeType>* node,const NodeTypeCB& cb){
        if(node->left != nullptr)
            _walk(node->left, cb);
        cb(node->data);
        if(node->right != nullptr)
            _walk(node->right, cb);
    }

public:
    SimpleTree() {
        _alloc = new Allocator();
        _root = nullptr;
    }

    void append(const NodeType& row){
        if(_root == nullptr){
            _root = _make_node(row);
        }
        else {
            _root->append(_make_node(row));
        }
    }

    ~SimpleTree() { 
        if(_root != nullptr)
            _destroy_node(_root);

        delete _alloc;
    }

    void walk(NodeTypeCB cb) {
        if(_root != nullptr)
            _walk(_root, cb);
    }
};


}} // namespace pirates::helpers

#endif // SIMPLETREE_H
