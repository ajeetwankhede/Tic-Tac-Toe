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
 *  @file    TicTacToe.cpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief Coding challenge by Plus One Robotics
 *
 *  @section DESCRIPTION
 *  This is a TicTacToe class source file.
 *  This class is used to initialize the board and start the game.
 *  Also, the type of player is selected here.
 *  The total number of games are counted.
 */

#include "TicTacToe.hpp"
#include <iostream>
#include <string>
#include "Board.hpp"
#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

TicTacToe::~TicTacToe() {
  // Auto-generated destructor stub
}

bool TicTacToe::continueGame() {
  // Count the number of games and
  // return false if count == 9 else true
  if (countGames == 9) {
    return false;
  }
  return true;
}

void TicTacToe::startGame(Board *b, Player *p1, Player *p2) {
  cout << "********" << p1->getName() << " vs " << p2->getName() << "********"
       << endl;
  // Start the while loop for the game
  cout << b->drawBoard();
  b->clearBoard();
  while (continueGame()) {
    // Find & Print the valid moves
    p1->findValidMoves(b->getEBoard());
    // Enter move
    int move;
    move = p1->input();
    // Update the board
    b->updateBoard(move);
    countGames++;
    // Check for win
    if (b->isWin()) {
      cout << p1->getName() << " wins!" << endl;
      return;
    } else if (continueGame()) {
      // Toggle the marker
      b->toggleMarker();
      // Find & Print the valid moves
      p2->findValidMoves(b->getEBoard());
      // Enter move
      move = p2->input();
      // Update the board
      b->updateBoard(move);
      countGames++;
      // Check for win
      if (b->isWin()) {
        cout << p2->getName() << " wins!" << endl;
        return;
      }
      // Toggle the marker
      b->toggleMarker();
    }
  }
  // Match is a Draw
  cout << "Match is a draw." << endl;
}
