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
 *  @brief
 *  This is a TicTacToe class source file.
 *  This class is used basically to initialize the board and start the game.
 *  Also, the type of player is selected here.
 *
 */

#include "TicTacToe.hpp"
#include <iostream>
#include <string>
#include "Board.hpp"
#include "Player.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;

TicTacToe::~TicTacToe() {
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
  if (!testing) {
    cout << "********" << p1->getName() << " vs " << p2->getName() << "********"
         << endl;
    cout << b->drawBoard();
  }
  b->clearBoard();
  countGames = 0;
  // Start the while loop for the game
  while (continueGame()) {
    // Find & Print the valid moves
    p1->findValidMoves(b->getEBoard());
    // Enter move
    int move;
    p1->player = b->getMarker();
    move = p1->input();
    // Update the board
    b->updateBoard(move);
    countGames++;
    // Check for win
    if (b->isWin()) {
      if (!testing) {
        cout << p1->getName() << " wins!" << endl;
      }
      return;
    } else if (continueGame()) {
      // Toggle the marker
      b->toggleMarker();
      // Find & Print the valid moves
      p2->findValidMoves(b->getEBoard());
      // Enter move
      p2->player = b->getMarker();
      move = p2->input();
      // Update the board
      b->updateBoard(move);
      countGames++;
      // Check for win
      if (b->isWin()) {
        if (!testing) {
          cout << p2->getName() << " wins!" << endl;
        }
        return;
      }
      // Toggle the marker
      b->toggleMarker();
    }
  }
  if (!testing) {
    // Match is a Draw
    cout << "Match is a draw." << endl;
  }
}

void TicTacToe::testAccuracy(Board *b, Player *p1, Player *p2) {
  win = 0;
  draw = 0;
  int test = 0;
  b->testing = true;
  testing = true;
  p1->testing = true;
  p2->testing = true;
  while (test < tests) {
    startGame(b, p1, p2);
    b->setMarker('X');
    if (b->isWin()) {
      win++;
    } else if (countGames == 9) {
      draw++;
    }
    test++;
  }
  if (testing) {
    cout << "Wins: " << win / 10.0 << "%" << endl;
    cout << "Draws: " << draw / 10.0 << "%" << endl;
    cout << "Loses: " << (tests - win - draw) * tests / 100.0 << "%" << endl;
  }
}
