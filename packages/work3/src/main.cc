#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <cstdlib>

#include <allocator.h>
#include <simpletree.h>

using namespace std;

struct S {
    int A;
    float B;
    bool C;

    S(int a, float b, bool c) : A(a), B(b), C(c) {}

    void print(){
        cout<<"A="<<A<<", B="<<B<<",C="<<C<<endl;
    }
};

int main() {

  cout<<"Allocator work"<<endl;

  // using MPS = otus::memory::MemoryPage<S>;

  // MPS p(1);
  // std::vector<MPS> v;

  // for(size_t i = 0; i < 5; ++i){
  //   cout<<"Init, i="<<i<<endl;
  //   v.emplace_back(1);
  //   cout<<"Finish"<<endl;
  // }

  // std::cout<<"123"<<endl;
  // auto* ptr = p.allocate(1);

  // cout<<ptr<<endl;
  

  // new (ptr) S(42,42.24,true);

  // ptr->print();

  
 
    map<string, int, std::less<string>, otus::memory::Allocator<std::pair<string, int>, 1>> m;

     m.emplace("aaa", 100);
     m.emplace("bbb", 200);
     m.emplace("ccc", 300);

// std::vector<int, otus::memory::Allocator<int, 10>> v;
//   v.push_back(10);
//   v.push_back(12);

//   v.reserve(2);
//   v.push_back(13);
//   for(auto& r : v){
//     cout<<r<<endl;
//   }

    for(auto& pair : m){
        cout<<pair.first<<" -> "<<pair.second<<endl;
   }

//     size_t n  = 2;
//     size_t size = sizeof(S);
  
//     cout<<"SIZE: "<<size<<endl;

//     void* mem = std::malloc(n * size);

//     cout<<sizeof(mem)<<endl;

//   S* ptr = static_cast<S*>(mem);

//   new (ptr) S(42,42.42,true);
//   ptr->print();

//   S* ptr2 = static_cast<S*>(mem + size);
//   new (ptr2) S(43,43.43,true);

//    mem = std::realloc(mem, (n + 2) * size);

//   // S* ptr3 = static_cast<S*>(mem + size  * 2);
//   // new (ptr3) S(45,45.45,true);

//   ptr->print();
//   ptr2->print();
//   // ptr3->print();

// //   // size_t pos = 0;

//   free(mem);
  // for(size_t i = 0; i < 5; i++){
  //   S*ptr = mem + (pos * size);
  //   pos++;
  //   cout<<ptr<<endl;
  //   new(ptr) S(i,i,true);
  //   ptr->print();
  // }

  //   S* ptr = mem;

  //   S* ptr2 = ptr + sizeof(S);

  //   cout<<ptr<<endl;        
  //   cout<<ptr2<<endl;

  //   new (ptr) S(42,42.42,true);
  //   new (ptr2) S(43,43.43,true);

  //   cout<<ptr<<endl;

  //   ptr->print();

  //   ptr2->print();
   // mem[0]->print();

   // auto a = mem[0];

    // mem[1] = S(42,42.42,true);
    // mem[1].print();

    // mem = static_cast<S*>(std::realloc(mem, (n+1) * sizeof(S)));

    // mem[2] = S(45,42.42,true);
    // mem[2].print();



    //free(mem);
    
    
    //mem[pos] = static_cast<S>(std::malloc(sizeof(S)));
    // mem[pos] = new S(42,42.42,false);
    // mem[pos + 1] =  new S(43,43.43,false);
    // mem[pos + 2] =  new S(44,44.44,false);
   
   //  mem[pos+2]->print();

   //  auto a = mem[pos];
   //  a->print();

   // 
   //  a->print();
   // // mem[pos + 1].print();
    
   return 0;


}
