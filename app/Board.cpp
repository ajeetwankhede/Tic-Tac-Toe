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
 *  @brief
 *  This is a Board class source file.
 *  This class is used to operate upon the board for Tic Tac Toe game.
 *  Utility functions such as draw, clear, toggle, update, and check win are provided.
 *
 */

#include "Board.hpp"
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Board::~Board() {
}

string Board::drawBoard() {
  std::stringstream ss;
  // Print the current status of the board
  ss << endl;
  for (int i = 1; i <= 9; i = i + 3) {
    ss << " " << getBoard(i) << " | " << getBoard(i + 1) << " " << " | "
         << getBoard(i + 2) << endl;
    if (i < 5) {
      ss << "------------" << endl;
    }
  }
  ss << endl;
  return ss.str();
}

void Board::clearBoard() {
  // Clear the content of the board
  string blank(9, ' ');
  setBoard(blank);
}

void Board::updateBoard(int pos) {
  // Update the board at the position with current marker
  board[pos - 1] = getMarker();
  if (!testing) {
    cout << drawBoard();
  }
}

void Board::toggleMarker() {
  // Toggle the value in the marker
  if (getMarker() == 'X') {
    setMarker('O');
  } else if (getMarker() == 'O') {
    setMarker('X');
  }
}

bool Board::isWin() {
  // Check if current marker is winning and
  // return true if win else false
  if (getBoard(1) == getMarker() && getBoard(1) == getBoard(2)
      && getBoard(1) == getBoard(3)) {
    // Row 1
    return true;
  } else if (getBoard(4) == getMarker() && getBoard(4) == getBoard(5)
      && getBoard(4) == getBoard(6)) {
    // Row 2
    return true;
  } else if (getBoard(7) == getMarker() && getBoard(7) == getBoard(8)
      && getBoard(7) == getBoard(9)) {
    // Row 3
    return true;
  } else if (getBoard(1) == getMarker() && getBoard(1) == getBoard(4)
      && getBoard(1) == getBoard(7)) {
    // Column 1
    return true;
  } else if (getBoard(2) == getMarker() && getBoard(2) == getBoard(5)
      && getBoard(2) == getBoard(8)) {
    // Column 2
    return true;
  } else if (getBoard(3) == getMarker() && getBoard(3) == getBoard(6)
      && getBoard(3) == getBoard(9)) {
    // Column 3
    return true;
  } else if (getBoard(1) == getMarker() && getBoard(1) == getBoard(5)
      && getBoard(1) == getBoard(9)) {
    // Diagonal
    return true;
  } else if (getBoard(3) == getMarker() && getBoard(3) == getBoard(5)
      && getBoard(3) == getBoard(7)) {
    // Anti Diagonal
    return true;
  }
  return false;
}

void Board::setBoard(string b) {
  // Set the board to new state
  board = b;
}

char Board::getBoard(const int pos) {
  // Return the value of the board at pos
  return board[pos - 1];
}

string Board::getEBoard() {
  // Return the the board
  return board;
}

void Board::setMarker(const char c) {
  // Set the value of the marker
  marker = c;
}

char Board::getMarker() {
  // Return the value of the marker
  return marker;
}
