// include/kinggame/Cli.hxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_CLI_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_CLI_HXX_

#include <string>
#include <vector>

#include "Player.hxx"
#include "Room.hxx"
#include "World.hxx"

namespace kinggame {
class Cli {
public:
  Cli();
  Cli(std::vector<Room>);
  ~Cli();

  void start();
  inline void quit();

  World world;
  Player p1;

private:
  bool running_;
  std::vector<std::string> verbs_;
  std::vector<std::string> adj_;
  std::vector<std::string> nouns_;

  std::string prompt();
  std::vector<std::string> parts(const std::string);
  void parse(const std::vector<std::string>);
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_CLI_HXX_
