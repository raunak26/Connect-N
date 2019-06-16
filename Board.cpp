//
// Created by Raunak Anand on 2019-04-30.
//

#include "ConnectNGame.hpp"


ConnectNGame::Board::Board(int length, int breadth, char blankChar) : boardState(length, std::string(breadth, blankChar)), blankChar(blankChar) {
  (*this).length = length;
  (*this).breadth = breadth;
}

int ConnectNGame::Board::getBreadth() const {
    return breadth;
}

int ConnectNGame::Board::getLength() const{
    return length;
}

void ConnectNGame::Board::display() const {

  //print column headers
  std::cout << "  ";
  for (int i = 0; i < boardState[0].size(); i++) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  for (int i = boardState.size() - 1; i >= 0; i--) {
    std::cout << i << " ";
    for (char j : boardState[i]) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}

bool ConnectNGame::Board::inBounds(int row, int col) const {
  return isBetween(row, 0, getBreadth()) &&
      isBetween(col, 0, getBreadth() - 1);
}

bool ConnectNGame::Board::isBetween(int val, int lower, int upper) {
  return val >= lower && val <= upper;
}

bool ConnectNGame::Board::isBlankSpace(int row, int col) const {
  return boardState[row][col] == blankChar;
}

void ConnectNGame::Board::set(int row, int col, char val) {
  boardState[row][col] = val;
  currentRow = row;
  currentCol = col;

}

const char& ConnectNGame::Board::at(int row, int col) const {
  return boardState[row][col];
}

const char ConnectNGame::Board::getBlankChar() const {
  return blankChar;
}

bool ConnectNGame::Board::full() const {
  int count = 0;
  for (int row = 0; row < getLength(); ++row) {
    for (int col = 0; col < getBreadth(); ++col) {
      if (boardState[row][col] == '*') {
        count++;
      }
    }

  }
  return count <= 0;
}



