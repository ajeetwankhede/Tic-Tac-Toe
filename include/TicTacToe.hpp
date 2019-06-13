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
 *  @brief Coding challenge by Plus One Robotics
 *
 *  @section DESCRIPTION
 *  This is a TicTacToe class header file.
 *  This class is used to initialize the board and start the game.
 *  Also, the type of player is selected here.
 *  The total number of games are counted.
 */

#ifndef INCLUDE_TICTACTOE_HPP_
#define INCLUDE_TICTACTOE_HPP_

class TicTacToe {
 public:
  /**
   *   @brief Default constructor for TicTacToe.
   *
   *   @param nothing
   *   @return nothing
   */
  TicTacToe();
  /**
   *   @brief Default constructor for TicTacToe.
   *
   *   @param nothing
   *   @return nothing
   */
  virtual ~TicTacToe();
  /**
   *   @brief Begins the game loop.
   *
   *   @param nothing
   *   @return nothing
   */
  void startGame();
  /**
   *   @brief Toggles the value of player between the two selected players ('H', 'R').
   *
   *   @param nothing
   *   @return nothing
   */
  void togglePlayer();
  /**
   *   @brief Tells if game is completed.
   *
   *   @param nothing
   *   @return bool value, true if continue else false to stop the game
   */
  bool continueGame();

  int countGames;
  char player;
};

#endif  // INCLUDE_TICTACTOE_HPP_
