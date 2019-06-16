//
// Created by Raunak Anand on 2019-04-30.
//

// adapted from Professor Butner's TicTacToe

#ifndef CONNECTN__PLAYER_H
#define CONNECTN__PLAYER_H

#include <string>
namespace ConnectNGame {
class Player {
 public:
  Player();
  const std::string &getName() const;
  char getPiece() const;
  bool validName(std::string name);
  static int numPlayer;
  static std::string playerName;
  static char Piece;
 private:
  std::string name;
  char piece;
};
}


#endif //CONNECTN__PLAYER_H
