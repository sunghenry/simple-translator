#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <unordered_map>

#include "base.hpp"

void Base::evaluatePerformance(std::string filename)
{
  std::cout << "evaluating " << getName() << " using phrases from " << filename << std::endl;
  populate(filename);
  std::cout << "measuring runtime..." << std::endl;
  std::cout << "total time to translate all phrases: " << measureRuntime() << " ms" << std::endl;
}

void Base::populate(std::string filename)
{
  std::cout << "loading phrases file..." << std::endl;
  std::ifstream in_file(filename);

  char phrase[_MAX_BUFF_SIZE];
  char translation[_MAX_BUFF_SIZE];

  while (in_file.good()) {
    in_file.getline(phrase, _MAX_BUFF_SIZE);
    if (!in_file.good())
      break;

    in_file.getline(translation, _MAX_BUFF_SIZE);
    if (!in_file.good())
      break;

    // avoid duplicate
    if (_phrases.count(phrase) == 0) {
      addPhrase(phrase, translation);
      _phrases[phrase] = translation;
    }
  }

  std::cout << "loaded " << _phrases.size() << " unique phrases" << std::endl;
}

double Base::measureRuntime()
{
  auto t1 = std::chrono::high_resolution_clock::now();

  for (auto phrase_pair: _phrases) {
    std::string phrase = phrase_pair.first;
    std::string translation = phrase_pair.second;
    std::string result = translate(phrase);

    if (result.compare(translation) != 0) {
      std::cout << "error" << std::endl;
      std::cout << "<" << phrase << "> got translated as <" << result << "> and not <" << translation << ">" << std::endl;
    }
  }

  auto t2 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duration = t2 - t1;
  return duration.count();
}
