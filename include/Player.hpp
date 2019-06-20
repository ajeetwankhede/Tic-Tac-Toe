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
 *  @brief
 *   *  This is a Player class header file.
 *  This class is be used find the valid moves in the game and to display them.
 *  These will be helpful for the players to choose and validate a valid move.
 *
 */

#ifndef INCLUDE_PLAYER_HPP_
#define INCLUDE_PLAYER_HPP_

#include <vector>
#include <string>

class Player {
  std::string name;

 public:
  /**
   *   @brief Default constructor for Player.
   */
  Player()
      : testing(false),
        player('X') {
  }
  /**
   *   @brief Default destructor for Player.
   */
  virtual ~Player();
  /**
   *   @brief Finds the moves available for the player.
   *   @param board a string of current board
   */
  void findValidMoves(std::string board);
  /**
   *   @brief Prints the moves available for the player.
   *   @return string containing valid moves
   */
  std::string displayValidMoves();
  /**
   *   @brief Validates the move for the player.
   *   @param pos an integer on the board
   *   @return True if valid move else false
   */
  bool checkMove(int pos);
  /**
   *   @brief Set the name of the player
   *   @param s a string value of name
   */
  void setName(std::string s);
  /**
   *   @brief Get the name of the player
   *   @return Value of name
   */
  std::string getName();
  /**
   *   @brief Chooses a position.
   *   @return The chosen position.
   */
  virtual int input();
  /**
   *   @brief Stores the state of board
   */
  std::string currentBoard;
  /**
   *   @brief Stores the valid moves
   */
  std::vector<int> validMoves;
  /**
   *   @brief Stores the marker of player
   */
  char player;
  /**
   *   @brief true if testing else false
   */
  bool testing;
};

#endif  // INCLUDE_PLAYER_HPP_
