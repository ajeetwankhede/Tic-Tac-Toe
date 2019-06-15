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
 *  @file    Player.cpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief Coding challenge by Plus One Robotics
 *
 *  @section DESCRIPTION
 *  This is a Player class source file.
 *  This class is be used find the valid moves in the game.
 *  These will be helpful for the players to choose a valid move.
 */

#include "Player.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

using std::cout;
using std::endl;
using std::string;

Player::Player() {
  // Auto-generated constructor stub
}

Player::~Player() {
  // Auto-generated destructor stub
}

void Player::findValidMoves(string board) {
  // Find the moves which are left to be played and
  // store the positions in validMoves
  validMoves.clear();
  currentBoard = board;
  for (int i = 1; i <= 9; i++) {
    if (board[i - 1] == ' ') {
      validMoves.push_back(i);
    }
  }
  cout << displayValidMoves();
}

string Player::displayValidMoves() {
  // Print valid moves array with delimiter ','
  std::stringstream ss;
  if (!validMoves.empty()) {
    std::ostringstream oss;
    ss << "Moves remaining: ";
    std::copy(validMoves.begin(), validMoves.end() - 1,
              std::ostream_iterator<int>(oss, ","));
    oss << validMoves.back();
    ss << oss.str() << endl;
  } else {
    ss << "No moves left." << endl;
  }
  return ss.str();
}

bool Player::checkMove(int pos) {
  // Validate the move for the player
  if (pos < 1 || pos > 9) {
    cout << "Move should be between 1-9 inclusive." << endl;
    return false;
  } else if (currentBoard[pos - 1] != ' ') {
    cout << "Position already occupied. Enter again." << endl;
    return false;
  }
  return true;
}

void Player::setName(string s) {
  // Store the name of the player
  name = s;
}

string Player::getName() {
  // Return the name of the player
  return name;
}

int Player::input() {
  // Return 1. Defined in derived class.
  return 1;
}
