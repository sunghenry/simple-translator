#ifndef BASE_HPP
#define BASE_HPP

#include <string>
#include <unordered_map>

class Base
{
  public:
    virtual std::string getName(void) = 0;
    virtual void addPhrase(std::string phrase, std::string translation) = 0;
    virtual std::string translate(std::string phrase) = 0;

    void evaluatePerformance(std::string filename);

  private:
    void populate(std::string filename);
    double measureRuntime(void);

    static const int _MAX_BUFF_SIZE = 256;
    std::unordered_map<std::string, std::string> _phrases;
};

#endif
