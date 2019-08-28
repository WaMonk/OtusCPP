#ifndef OTUS_ALLOCATOR_H
#define OTUS_ALLOCATOR_H

#include <memory>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

namespace otus {
    namespace memory {

        template<typename T>
        class MemoryPage {
        public:
            struct MemoryPtr
            {
                T* ptr;
                size_t max_size;
                bool used;

                MemoryPtr(T* ptr, size_t msize) : ptr(ptr), max_size(msize), used(false) {}
                MemoryPtr(void* ptr, size_t msize) : ptr(static_cast<T*>(ptr)), max_size(msize), used(false) {}

                void print() const {
                    std::cout<<" ptr: "<<ptr<<", msize: "<<max_size<<", used: "<<used<<std::endl;       
                }

                ~MemoryPtr(){
                    if(used)
                        ptr->~T();
                }
            };

            MemoryPage(const MemoryPage &p2) = delete;
            MemoryPage& operator=(const MemoryPage&) = delete;
            
            MemoryPage(MemoryPage&& o) noexcept  {
                _root = std::move(o._root);
                _pool = std::move(o._pool);
                _page_size = std::move(o._page_size);
                _obj_size = std::move(o._obj_size);

                o._root = nullptr;
                o._pool = nullptr;
            }

            MemoryPage& operator=(MemoryPage&&o) noexcept {
                _root = std::move(o._root);
                _pool = std::move(o._pool);
                _page_size = std::move(o._page_size);
                _obj_size = std::move(o._obj_size);

                o._root = nullptr;
                o._pool = nullptr;
            }

            MemoryPage(size_t page_size) {
                _page_size = page_size;
                _obj_size = sizeof(T);
                    
                size_t pool_size = _page_size * sizeof(MemoryPtr);
                _root = malloc(_page_size * _obj_size +  pool_size);
                _pool = static_cast<MemoryPtr*>(_root);
                char* _root_addr = static_cast<char*>(_root);

                for(size_t i = 0; i < _page_size; i++){
                    new(_pool + i) MemoryPtr(_root_addr + pool_size + (i * _obj_size),  _page_size - i);
                }
            }

            bool deallocate(T* ptr, size_t count = 1) const{
               
                for(size_t i = 0; i < _page_size; i++){
                    if(_pool[i].ptr != ptr)
                        continue;

                    if(i + count - 1 > _page_size)
                        throw std::logic_error("Bad count on deallocate"); 

                    size_t j = 1;
                    while( j < count){
                        _pool[i+j].used = false;
                        j++;
                    }

                    _pool[i].used = false;

                    size_t msize = 1;
                    for(size_t p = _page_size - 1; p >= i && p < _page_size ; p--){
                        if(_pool[p].used){
                            msize = 1; 
                        }
                        else{
                            _pool[p].max_size = msize;
                            msize++;
                        }
                    }

                    return true;
                }

                return false;
            }

            T* allocate(size_t count) const {
                for(size_t i = 0; i < _page_size; i++){ 
                        if(_pool[i].used)
                            continue;
                        if(_pool[i].max_size < count)
                            continue;

                        _pool[i].used = true;
                        _pool[i].max_size = 0;

                        size_t j = 1;
                        while(j < count){
                            _pool[i + j].used = true;
                            _pool[i + j].max_size = 0;
                            j++;
                        }

                        return static_cast<T*>(_pool[i].ptr);
                }
                
                return nullptr;
            }

            ~MemoryPage(){
                if(_pool){
                    for(size_t i = 0; i < _page_size; i++ ){
                        _pool[i].~MemoryPtr();
                    }
                }
                    
                if(_root)
                    free(_root);
                        
            }

            void print() const {
                 for(size_t i = 0; i < _page_size; i++){
                    std::cout<<"i: "<<i;
                    _pool[i].print();       
                }
            }
        private: 
            void* _root;
         
            MemoryPtr* _pool;

            size_t _page_size;
            size_t _obj_size;
        };

        template<typename T, size_t PageSize = 10>
        class Allocator  { 
            public:
                using value_type = T;
                using pointer = value_type*;
                using allocator_type = Allocator;
                using size_type = size_t;

                Allocator(){}

                ~Allocator(){}

                template<typename U>
                    struct rebind {
                        using other = Allocator<U,PageSize>;
                    };

                pointer allocate(size_t n){
                    if(n > std::size_t(-1) / sizeof(T))
                        throw std::bad_alloc();

                    pointer retval = nullptr;
                    for(const auto& page : _pages){
                        retval = page.allocate(n);
                        if(retval != nullptr)
                            break;
                    }

                    if(retval == nullptr){
                        _pages.emplace_back(n < PageSize ? PageSize : n);
                        const auto& page = _pages.back();
                        retval = page.allocate(n);
                    }
                    return retval;
                }

                void deallocate(pointer p, size_type n){
                    for(const auto& page : _pages){
                        if(page.deallocate(p, n))
                            break;
                    }
                }

                template<typename U, typename ...Args>
                void construct(U* p, Args &&...args){
                    new (p) U(std::forward<Args>(args)...);
                }

                void destroy(pointer p){
                    p->~T();
                }                

                static size_type max_size() {
                    return 100;
                }
             private:
                std::vector<MemoryPage<T>> _pages;
             
        };
    }
}

#endif
