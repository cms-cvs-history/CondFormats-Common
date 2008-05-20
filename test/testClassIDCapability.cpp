#include "CondFormats/Common/interface/ClassIDCapability.h"
#include <vector>

namespace condtest{

  class A{};

  class B{};

  typedef vector<int> V;

}


namespace {
  cond::ClassID<condtest::A> a;
  cond::ClassID<condtest::B> b;
  cond::ClassID<condtest::V> v;
}



#include<iostream>
int main() {


  const char** names; 
  int n=0;

  SEAL_CAPABILITIES(names,n);

  for (int i=0; i<n; i++)
    std::cout << names[i] << std::endl;


}
