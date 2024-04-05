#include <string>
#include <list>
#include <utility>

#include "list.hpp"

std::string List::getName()
{
  return "doubly linked list";
}

void List::addPhrase(std::string phrase, std::string translation)
{
  std::pair<std::string, std::string> pair;
  pair = std::make_pair(phrase, translation);
  _list.push_back(pair);
}

std::string List::translate(std::string phrase)
{
  for (std::pair<std::string, std::string> pair : _list) {
    if (pair.first.compare(phrase) == 0)
      return pair.second;
  }
  return NULL;
}
