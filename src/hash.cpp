#include <string>
#include <unordered_map>

#include "hash.hpp"

std::string Hash::getName()
{
  return "hash table";
}

void Hash::addPhrase(std::string phrase, std::string translation)
{
  _map[phrase] = translation;
}

std::string Hash::translate(std::string phrase)
{
  return _map[phrase];
}
