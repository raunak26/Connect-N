#include "ConnectNGame.hpp"

int main(int argc, char* argv[]) {

  int length = std::stoi(argv[1]); // length of the board
  int breadth = std::stoi(argv[2]); // width of the board
  int n = std::stoi(argv[3]); // connect "n"

  ConnectNGame::ConnectN game(length, breadth, n);
  game.play();

  return 0;
}