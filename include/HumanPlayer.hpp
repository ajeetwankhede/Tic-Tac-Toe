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
 *  @file    HumanPlayer.hpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief
 *  This is a HumanPlayer class header file.
 *  This class is be used to input a move by human.
 *
 */

#ifndef INCLUDE_HUMANPLAYER_HPP_
#define INCLUDE_HUMANPLAYER_HPP_

#include "Player.hpp"

class HumanPlayer : public Player {
 public:
  /**
   *   @brief Default constructor for HumanPlayer.
   */
  HumanPlayer();
  /**
   *   @brief Default destructor for HumanPlayer.
   */
  virtual ~HumanPlayer();
  /**
   *   @brief Asks the player to enter the move position.
   *   @return The chosen move.
   */
  int input();
};

#endif  // INCLUDE_HUMANPLAYER_HPP_
