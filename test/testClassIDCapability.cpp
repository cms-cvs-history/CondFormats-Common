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

CLASS_ID(ClassID<condtest::A);
CLASS_ID(ClassID<condtest::B);
CLASS_ID(ClassID<condtest::C);


#include<iostream>
int main() {


  const char** names; 
  int n=0;

  NON_SEAL_CAPABILITIES(names,n);

  for (int i=0; i<n; i++)
    std::cout << names[i] << std::endl;


}
