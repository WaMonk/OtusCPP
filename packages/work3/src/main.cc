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

  std::stringstream buffer1;
  std::stringstream buffer2;
  for(size_t i = 0; i < 10; i++){
    buffer1 << i << " "<< map1[i]<< std::endl;
    buffer2 << i << " "<< map2[i]<< std::endl;
  }

  buffer1.flush();
  buffer2.flush();

  std::cout<<buffer1.str()<<std::endl;
  std::cout<<buffer2.str()<<std::endl;

  std::stringstream buffer3;
  std::stringstream buffer4;

  otus::data::SimpleTree<int> tree;
  for(size_t i = 0; i < 10; i++){
      tree.append(i);
  }

  otus::data::SimpleTree<int, otus::memory::Allocator<otus::data::TreeNode<int>, 10>> tree1;
  for(size_t i = 0; i < 10; i++){
      tree1.append(i);
  }

  tree.walk([&buffer3](const int& row) -> void { buffer3<<row<<std::endl; });
  tree1.walk([&buffer4](const int& row) -> void { buffer4<<row<<std::endl;});

  buffer3.flush();
  buffer4.flush();

  std::cout<<buffer3.str()<<std::endl;
  std::cout<<buffer4.str()<<std::endl;
 
  return 0;
}
