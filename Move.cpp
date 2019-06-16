//
// Created by Raunak Anand on 2019-04-30.
//

#include "ConnectNGame.hpp"

ConnectNGame::Move::Move(const ConnectNGame::Player& maker) : maker(maker), row(-99), col(-98), parsedSuccessfully(false) {

}

void ConnectNGame::Move::parseInput(const Board& board, std::stringstream& input) {
  parsedSuccessfully = static_cast<bool>(input); //input must start out as being good

  input >> col;
  //we must have read col
  parsedSuccessfully = parsedSuccessfully && static_cast<bool>(input);
  std::string leftovers;
  input >> leftovers;
  //and we weren't able to read anything after the row and col
  parsedSuccessfully = parsedSuccessfully && !input;
  row = 0;

  while (!board.isBlankSpace(row, col) && board.inBounds(row, col)) {
    row++;
  }

}

bool ConnectNGame::Move::isValid(const Board& board) const {

  return parsedSuccessfully &&
      board.inBounds(row, col) &&
      board.isBlankSpace(row, col);

}

void ConnectNGame::Move::make(ConnectNGame::Board& board) {
  board.set(row, col, maker.getPiece());
}
