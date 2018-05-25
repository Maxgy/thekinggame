// include/kinggame/Cli.hxx
//
// Maxwell Anderson 2018

#ifndef THEKINGGAME_INCLUDE_KINGGAME_CLI_HXX_
#define THEKINGGAME_INCLUDE_KINGGAME_CLI_HXX_

#include <memory>
#include <string>
#include <vector>

#include "Player.hxx"
#include "Room.hxx"
#include "World.hxx"

namespace kinggame {
class Cli {
public:
  Cli();
  Cli(std::vector<std::unique_ptr<Room>>);

  void start();
  inline void quit();

  World world_;
  Player p1_;

private:
  bool running_;
  std::vector<std::string> cmds_;
  std::vector<std::string> verbs_;
  std::vector<std::string> preps_;
  std::vector<std::string> adjs_;
  std::vector<std::string> nouns_;

  std::string prompt();
  std::vector<std::string> parts(std::string);
  std::vector<std::string> filter(std::vector<std::string>);
  void parse(std::vector<std::string>);
};
} // namespace kinggame

#endif // THEKINGGAME_INCLUDE_KINGGAME_CLI_HXX_
