// include/kinggame/Cli.hxx
//
// Maxwell Anderson 2018

#ifndef INCLUDE_KINGGAME_CLI_HXX_
#define INCLUDE_KINGGAME_CLI_HXX_

#include <string>
#include <vector>

#include "World.hxx"
#include "Player.hxx"

namespace kinggame {
class Cli {
 public:
  Cli();

  void start();
  inline void quit();

 private:
  bool running_;
  World world_;
  Player p1_;
  std::vector<std::string> verbs;
  std::vector<std::string> adj;
  std::vector<std::string> nouns;

  std::string prompt();
  std::vector<std::string> parts(const std::string);
  void parse(const std::vector<std::string>);
};
}  // namespace kinggame

#endif  // INCLUDE_KINGGAME_CLI_HXX_
