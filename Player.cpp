//
// Created by Raunak Anand on 2019-04-30.
//

#include "ConnectNGame.hpp"


ConnectNGame::Player::Player() {
  std::string leftover;
  do {
    std::cout << "Player " << numPlayer << ", please enter your name: ";
    getline(std::cin, name);
  } while (validName(name) || playerName == name);

  playerName = name;

  do {
    std::cout << name << ", please enter the character you want to use for your piece: ";
    std::cin >> piece;
    std::getline(std::cin, leftover);
  } while (!leftover.empty() || Piece == piece);

  Piece = piece;
  numPlayer++;
}

const std::string& ConnectNGame::Player::getName() const {
  return name;
}

char ConnectNGame::Player::getPiece() const {
  return piece;
}

bool ConnectNGame::Player::validName(std::string name) {
  for (char i : name) {
    if (i == ' ') {
      return true;
    }
  }
  return false;

}
