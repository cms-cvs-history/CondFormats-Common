#include "CondFormats/Common/interface/ClassIDCapability.h"
#include <vector>

namespace condtest{

  class A{};

  class B{};

  typedef std::vector<int> V;

}

/*
namespace {
  cond::ClassID<condtest::A> a;
  cond::ClassID<condtest::B> b;
  cond::ClassID<condtest::V> v;
}
*/

CLASS_ID(condtest::A, ca);

CLASS_ID(condtest::B, cb);

CLASS_ID(condtest::V, cv);


#include<iostream>
int main() {


  const char** names; 
  int n=0;

  NOT_SEAL_CAPABILITIES(names,n);

  for (int i=0; i<n; i++)
    std::cout << names[i] << std::endl;


}
