//
// Created by Raunak Anand on 2019-04-30.
//

// adapted from Professor Butner's TicTacToe

#include "ConnectNGame.hpp"

int ConnectNGame::Player::numPlayer = 1;
std::string ConnectNGame::Player::playerName;
char ConnectNGame::Player::Piece = ' ';

ConnectNGame::ConnectN::ConnectN(int length, int breadth, int n) : board(length, breadth, '*'), players(2), playerTurn(-1), winN(n) {

}

void ConnectNGame::ConnectN::play() {
  determineStartingPlayer();

  while (true) {
    board.display(); //show the board after each turn

    Move move = getValidMove(); // check if the move is valid; if that move has been previously made
    //make move

    move.make(board);
    //makeMove(move);
    if (isGameOver(winN)) {
      break;
    }
    //switch the turn
    changeTurn();
  }
  //
  board.display();
  //declare the results
  declareResults(winN);

}

void ConnectNGame::ConnectN::determineStartingPlayer() {
    playerTurn = 0;
}

ConnectNGame::Move ConnectNGame::ConnectN::getValidMove() const {
    Move playerMove(getCurrentPlayer());
    do {
        std::cout << getCurrentPlayer().getName()<< ", please enter a column to play in: ";
        std::string line;
        std::getline(std::cin, line);
        std::stringstream userIn(line);
        playerMove.parseInput(board, userIn);
    } while (!playerMove.isValid(board));
    return playerMove;
}

const ConnectNGame::Player& ConnectNGame::ConnectN::getCurrentPlayer() const {
    return players.at(playerTurn);


}


bool ConnectNGame::ConnectN::isGameOver(int n) const {
    return isGameWon(n) || tie(n);
}

bool ConnectNGame::ConnectN::isGameWon(int n) const {
    return vertWin(n) || horzWin(n) || rightDiagWin(n) || leftDiagWin(n);
}

void ConnectNGame::ConnectN::declareResults(int n) const {
    if (tie(n)) {
        std::cout << "Tie game." << std::endl;
    } else {
        std::cout << getCurrentPlayer().getName() << " won the game!" << std::endl;
    }
}

bool ConnectNGame::ConnectN::tie(int n) const {
    return !isGameWon(n) && board.full();
}


void ConnectNGame::ConnectN::changeTurn() {
    playerTurn = (playerTurn + 1) % players.size();
}

bool ConnectNGame::ConnectN::vertWin(int n) const{
    int count = 0;
    char piece = getCurrentPlayer().getPiece();
    for (int col = 0; col != board.getBreadth(); ++col) {
        for(int row=0;row < board.getLength();row++){
            if (board.isBlankSpace(row, col)) {
                break;
            }
            else if(board.at(row,col) == piece){
                count++;
                if(count == n){
                    return true;
                }
            }
            else{
                count=0;
            }
        }
        count=0;
    }
    return false;


}

bool ConnectNGame::ConnectN::horzWin(int n) const{
    int count = 0;
    char piece = getCurrentPlayer().getPiece();
    for (int row = 0; row != board.getLength(); ++row) {
        for(int col=0;col < board.getBreadth();++col){
            if(board.at(row,col) == piece){
                count++;
                if(count == n){
                    return true;
                }
            }
            else{
                count=0;
            }
        }
        count =0;

    }
    return false;


}

bool ConnectNGame::ConnectN::rightDiagWin(int winVar) const {
  int count = 0;
  char piece = getCurrentPlayer().getPiece();
  int itrRow = board.currentRow;
  int itrColumn = board.currentCol;

  while (itrRow > 0 && itrColumn <= board.getBreadth()) {
    itrRow -= 1;
    itrColumn += 1;
  }

  while (itrRow < board.getLength() && itrColumn >= 0) {
    if (board.at(itrRow, itrColumn) == piece) {
      count += 1;
    } else {
      count = 0;
    }
    if (count == winVar) {
      return true;
    }
    itrRow += 1;
    itrColumn -= 1;
  }
  return false;
}

bool ConnectNGame::ConnectN::leftDiagWin(int winVar) const {
  int count = 0;
  char piece = getCurrentPlayer().getPiece();
  int itrRow = board.currentRow;
  int itrColumn = board.currentCol;

  while (itrRow > 0 && itrColumn <= board.getBreadth()) {
    itrRow -= 1;
    itrColumn -= 1;
  }

  while (itrRow < board.getLength() && itrColumn >= 0) {
    if (board.at(itrRow, itrColumn) == piece) {
      count += 1;
    } else {
      count = 0;
    }
    if (count == winVar) {
      return true;
    }
    itrRow += 1;
    itrColumn += 1;
  }
  return false;
}



