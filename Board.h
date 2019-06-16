//
// Created by Raunak Anand on 2019-04-30.
//

#ifndef MIDTERM_GRID_H
#define MIDTERM_GRID_H

#include <vector>
#include <string>

namespace ConnectNGame {
class Board {
 public:

  using iterator = std::vector<std::string>::iterator;
  using const_iterator = std::vector<std::string>::const_iterator;

  explicit Board(int length, int breadth, char blankChar);
  // contructor with length, breadth and character '*' to denote each cell of the board
  int getBreadth() const;
  // returns the breadth of the board
  int getLength() const;
  // returns the length of the board
  void display() const;
  bool inBounds(int row, int col) const;
  bool isBlankSpace(int row, int col) const;
  void set(int row, int col, char val);
  const char &at(int row, int col) const;
  bool full() const;
  const char getBlankChar() const;
  int currentRow;
  int currentCol;

 private:
  static bool isBetween(int val, int lower, int upper);

 private:
  std::vector<std::string> boardState;
  const char blankChar;
  int length;
  int breadth;

};
}


#endif //MIDTERM_GRID_H
