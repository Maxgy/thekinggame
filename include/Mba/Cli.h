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
  std::string prompt();
  std::vector<std::string> parts(const std::string);
  void parse(const std::vector<std::string>);
  inline bool quit_words(const std::string);
 private:
  bool running_;
};
}  // namespace Mba

#endif  // INCLUDE_MBA_CLI_H_
