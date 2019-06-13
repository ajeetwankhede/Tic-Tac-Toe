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
 *  @file    Player.hpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief Coding challenge by Plus One Robotics
 *
 *  @section DESCRIPTION
 *  This is a Player class header file.
 *  This class is be used find the valid moves in the game.
 *  These will be helpful for the players to choose a valid move.
 */

#ifndef INCLUDE_PLAYER_HPP_
#define INCLUDE_PLAYER_HPP_

#include<vector>

class Player {
 public:
  /**
   *   @brief Default constructor for Player.
   *
   *   @param nothing
   *   @return nothing
   */
  Player();
  /**
   *   @brief Default destructor for Player.
   *
   *   @param nothing
   *   @return nothing
   */
  virtual ~Player();
  /**
   *   @brief Finds the moves available for the player.
   *
   *   @param char array of 3x3 stating the current board values.
   *   @return nothing
   */
  void findValidMoves(char board[9]);
  /**
   *   @brief Validates the move for the player.
   *
   *   @param int value of position.
   *   @return bool value, returns true if valid move else false
   */
  bool checkMove(int pos);

  char currentBoard[9];
  std::vector<int> validMoves;
};

#endif  // INCLUDE_PLAYER_HPP_
