#ifndef HASH_HPP
#define HASH_HPP

#include "base.hpp"

class Hash: public Base
{
  public:
    std::string getName(void);
    void addPhrase(std::string phrase, std::string translation);
    std::string translate(std::string phrase);

  private:
    std::unordered_map<std::string, std::string> _map;
};

#endif
