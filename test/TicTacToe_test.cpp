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
 *  @file    TicTacToe_test.cpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief Coding challenge by Plus One Robotics
 *
 *  @section DESCRIPTION
 *  This is a TicTacToe class test file.
 *  Test cases are written to ensure the implementation is correct. All test cases must pass.
 *  If any test case fails, please correct the corresponding function definition.
 */

#include "TicTacToe.hpp"
#include <gtest/gtest.h>
#include <memory>

std::shared_ptr<TicTacToe> TicTacToeTestObject;

/**
 * @brief Test case for togglePlayer function.
 */
TEST(TicTacToe, togglePlayerTest) {
  // Assign value to the shared pointer to the object
  TicTacToeTestObject = std::make_shared<TicTacToe>();
  // Assign player
  TicTacToeTestObject->player = 'H';
  // Call the togglePlayer function
  TicTacToeTestObject->togglePlayer();
  // Expect the value of player has been changed
  EXPECT_EQ(TicTacToeTestObject->player, 'R');
  // Assign player
  TicTacToeTestObject->player = 'R';
  // Call the togglePlayer function
  TicTacToeTestObject->togglePlayer();
  // Expect the value of player has been changed
  EXPECT_EQ(TicTacToeTestObject->player, 'H');
}

/**
 * @brief Test case for continueGame function.
 */
TEST(TicTacToe, continueGameTest) {
  // Assign value to the shared pointer to the object
  TicTacToeTestObject = std::make_shared<TicTacToe>();
  // Initialize countGames to 1
  TicTacToeTestObject->countGames = 1;
  // Expect game to be continued
  EXPECT_TRUE(TicTacToeTestObject->continueGame());
  // Initialize countGames to 9
  TicTacToeTestObject->countGames = 9;
  // Expect game to stop
  EXPECT_FALSE(TicTacToeTestObject->continueGame());
}
