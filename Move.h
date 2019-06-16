//
// Created by Raunak Anand on 2019-04-30.
//

// adapted from Professor Butner's TicTacToe

#ifndef CONNECTN__MOVE_H
#define CONNECTN__MOVE_H

#include <sstream>
#include "Player.h"
#include "Board.h"

namespace ConnectNGame {

class Move {
 public:
  Move(const Player &maker);
  void parseInput(const Board &board, std::stringstream &input);
  bool isValid(const Board &board) const;
  void make(Board &board);
 private:
  const Player &maker;
  int row, col;
  bool parsedSuccessfully;

};
}

#endif //CONNECTN__MOVE_H
