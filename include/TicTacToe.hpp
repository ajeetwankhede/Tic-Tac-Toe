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
 *  @file    TicTacToe.hpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief
 *  This is a TicTacToe class header file.
 *  This class is basically used to initialize the board and start the game.
 *  Also, the type of player is selected here.
 *
 */

#ifndef INCLUDE_TICTACTOE_HPP_
#define INCLUDE_TICTACTOE_HPP_

#include "Player.hpp"
#include "Board.hpp"

class TicTacToe {
 public:
  /**
   *   @brief Default constructor for TicTacToe.
   */
  TicTacToe()
      : countGames(0),
        testing(false),
        win(0),
        draw(0),
        tests(1000) {
  }
  /**
   *   @brief Default constructor for TicTacToe.
   */
  virtual ~TicTacToe();
  /**
   *   @brief Begins the game loop.
   *   @param b Board object pointer
   *   @param p1 Player1 object pointer
   *   @param p2 Player2 object pointer
   */
  void startGame(Board *b, Player *p1, Player *p2);
  /**
   *   @brief Tells if game is completed.
   *   @return True if continue else false to stop the game
   */
  bool continueGame();
  /**
   *   @brief Tests the accuracy of the player 1 against player 2
   *   @param b Board object pointer
   *   @param p1 Player1 object pointer
   *   @param p2 Player2 object pointer
   */
  void testAccuracy(Board *b, Player *p1, Player *p2);
  /**
   *   @brief Counts the number of steps taken in a game
   */
  int countGames;
  /**
   *   @brief true if testing else false
   */
  bool testing;
  /**
   *   @brief Stores the number of wins to find accuracy
   */
  int win;
  /**
   *   @brief Stores the number of draws to find accuracy
   */
  int draw;
  /**
   *   @brief Number of games to played for testing.
   */
  int tests;
};

#endif  // INCLUDE_TICTACTOE_HPP_
