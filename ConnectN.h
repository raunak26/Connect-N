//
// Created by Raunak Anand on 2019-04-30.
//

#ifndef CONNECTN__CONNECTN_H
#define CONNECTN__CONNECTN_H

#include <vector>
#include "Player.h"
#include "Board.h"
#include "Move.h"

namespace ConnectNGame {
class ConnectN {

 public:
  explicit ConnectN(int length, int breadth, int n); // constructor for ConnectNGame

  virtual ~ConnectN() = default; // destructor
  void play();
  void determineStartingPlayer();
  Move getValidMove() const;

  const Player &getCurrentPlayer() const;
  Player &getCurrentPlayer();

  bool isGameOver(int n) const;
  bool isGameWon(int n) const;

  bool horzWin(int n) const;
  bool vertWin(int n) const;
  bool leftDiagWin(int n) const;
  bool rightDiagWin(int n) const;
  // ways to win

  bool tie(int n) const;

  void changeTurn();

  void declareResults(int winVar) const;

 private:
  Board board;
  std::vector<Player> players;
  int playerTurn;
  int winN;
};
}


#endif //CONNECTN__CONNECTN_H
