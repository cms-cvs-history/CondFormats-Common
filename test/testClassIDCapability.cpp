#include "CondFormat/Common/interface/ClassIDCapability.h"
#include <vector>

namespace condtest{

  class A{};

  class B{};

  typedef vector<int> V;

}


namespace {
  ClassID<condtest::A> a;
  ClassID<condtest::B> b;
  ClassID<condtest::V> v;
}



#include<iostream>
int main() {


  const char** names; 
  int n=0;

  SEAL_CAPABILITIES(names,n);

  for (int i=0; i<n; i++)
    std::cout << names[i] << std::endl;


}
