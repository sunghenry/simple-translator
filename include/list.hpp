#ifndef LIST_HPP
#define LIST_HPP

#include <string>
#include <list>
#include <utility>

#include "base.hpp"

class List: public Base
{
  public:
    std::string getName(void);
    void addPhrase(std::string phrase, std::string translation);
    std::string translate(std::string phrase);

  private:
    std::list<std::pair<std::string, std::string>> _list;
};

#endif
