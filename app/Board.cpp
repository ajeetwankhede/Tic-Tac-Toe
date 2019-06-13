/************************************************************************
 MIT License
 Copyright (c) 2019 Ajeet Wankhede
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 *************************************************************************/

/**
 *  @copyright MIT License 2019 Ajeet Wankhede
 *  @file    Board.cpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief Coding challenge by Plus One Robotics
 *
 *  @section DESCRIPTION
 *  This is a Board class source file.
 *  This class is used to operate upon the board for Tic Tac Toe game.
 *  The current state of the board should be updated every iteration.
 *  Utility functions such as draw, clear, update, and check win are provided.
 */

#include "Board.hpp"

Board::Board() {
  // TODO(Ajeet): Auto-generated constructor stub
}

Board::~Board() {
  // TODO(Ajeet): Auto-generated destructor stub
}

void Board::drawBoard() {
  // TODO(Ajeet): Print the current status of the board
}

void Board::clearBoard() {
  // TODO(Ajeet): Clear the content of the board
}

void Board::updateBoard(int pos) {
  // TODO(Ajeet): Update the board at the position with current marker
}

void Board::toggleMarker() {
  // TODO(Ajeet): Toggle the value in the marker
}

bool Board::isWin() {
  // TODO(Ajeet): Check if current marker is winning and
  // return true if win else false
  return false;
}

void Board::setBoard(const char b[9]) {
  // Set the board to new state
  for (int i = 0; i < 9; i++) {
    board[i] = b[9];
  }
}

char Board::getBoard(const int pos) {
  // Return the value of the board at pos
  return board[pos];
}

void Board::setMarker(const char c) {
  // Set the value of the marker
  marker = c;
}

char Board::getMarker() {
  // Return the value of the marker
  return marker;
}
