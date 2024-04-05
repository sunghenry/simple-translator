#include <iostream>

#include "hash.hpp"
#include "list.hpp"

int main(void)
{
  Hash hash;
  hash.addPhrase("allo", "heya");
  hash.addPhrase("bonjour", "hello");
  std::cout << hash.translate("allo") << std::endl;
  std::cout << hash.translate("bonjour") << std::endl;
  std::cout << std::endl;

  List list;
  list.addPhrase("allo", "heya");
  list.addPhrase("bonjour", "hello");
  std::cout << list.translate("allo") << std::endl;
  std::cout << list.translate("bonjour") << std::endl;
  std::cout << std::endl;

  hash.evaluatePerformance("eng_lat.txt");
  std::cout << std::endl;
  list.evaluatePerformance("eng_lat.txt");
  return 0;
}
