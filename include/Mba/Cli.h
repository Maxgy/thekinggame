// Copyright 2018 Maxwell Anderson

#ifndef INCLUDE_MBA_CLI_H_
#define INCLUDE_MBA_CLI_H_

#include <string>
#include <vector>

namespace Mba {
class Cli {
 public: 
  Cli();
  
  void start();
  inline void quit();
 
 private:
  bool running_;
  std::vector<std::string> verbs;
  std::vector<std::string> adj;
  std::vector<std::string> nouns;
  
  std::string prompt();
  std::vector<std::string> parts(const std::string);
  void parse(const std::vector<std::string>);
};
}  // namespace Mba

#endif  // INCLUDE_MBA_CLI_H_
