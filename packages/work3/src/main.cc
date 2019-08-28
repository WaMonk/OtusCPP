#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <cmath>
#include <cstdlib>

#include <allocator.h>
#include <simpletree.h>

using std::map;

long factorial(long value){
  long retval = 1;
  long start = 1;
  while (start <= value){
    retval *= start++;
  }
  return retval;
}

int main() {

  std::cout<<"Default std::map with default std::allocator: "<<std::endl;
  map<int, long> map1;
  for(size_t i = 0; i < 10; i++){
     map1.emplace(i, factorial(i));
  }

  std::cout<<"Default std::map with otus::memory::Allocator: "<<std::endl;
  map<int, long, std::less<int>, otus::memory::Allocator<std::pair<int, long>,10>> map2;
  for(size_t i = 0; i < 10; i++){
     map2.emplace(i,factorial(i));
  }

  otus::data::SimpleTree<int> tree;

  for(size_t i = 0; i < 10; i++){
      tree.append(i);
  }

  tree.call_cb([](const int& row) -> void { std::cout<<std::to_string(row)<<std::endl;}, true);


  // std::stringstream buffer1;
  // std::stringstream buffer2;
  // for(size_t i = 0; i < 10; i++){
  //   buffer1 << i << " "<< map1[i]<< "\n";
  //   buffer2 << i << " "<< map2[i]<< "\n";
  // }

  // buffer1.flush();
  // buffer2.flush();

  // std::cout<<buffer1.str()<<std::endl;
  // std::cout<<buffer2.str()<<std::endl;
  
  
 
  return 0;

}
