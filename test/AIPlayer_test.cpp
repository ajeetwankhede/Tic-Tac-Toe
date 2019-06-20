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
 *  @file    AIPlayer_test.cpp
 *  @author  Ajeet Wankhede
 *  @date    06/19/2019
 *  @version 1.0
 *
 *  @brief
 *  This is a AIPlayer class test file.
 *  Test cases are written to ensure the implementation is correct. All test cases must pass.
 *  If any test case fails, please correct the corresponding function definition.
 *
 */

#include <AIPlayer.hpp>
#include <gtest/gtest.h>
#include <map>

/**
 * @brief Test case for input function for player 'X'.
 */
TEST(AIPlayer, inputTest1) {
  // Create an object of class AIPlayer
  AIPlayer AIPlayerTestObject;
  // Set the board
  AIPlayerTestObject.currentBoard = "XXOXOO   ";
  // Set the marker
  AIPlayerTestObject.player = 'X';
  // Add valid moves and values
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  AIPlayerTestObject.table.insert(
      std::make_pair("XXOXOO   X", actionValue));
  // Call the input function to select a move
  int move = AIPlayerTestObject.input();
  // Expect the move is the highest action value pair for 'X'
  EXPECT_EQ(move, 9);
}

/**
 * @brief Test case for input function for player 'O'.
 */
TEST(AIPlayer, inputTest2) {
  // Create an object of class AIPlayer
  AIPlayer AIPlayerTestObject;
  // Set the board
  AIPlayerTestObject.currentBoard = "XXOXOO   ";
  // Set the marker
  AIPlayerTestObject.player = 'O';
  // Add valid moves and values
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  AIPlayerTestObject.table.insert(std::make_pair("XXOXOO   O", actionValue));
  // Call the input function to select a move
  int move = AIPlayerTestObject.input();
  // Expect the move is the lowest action value pair for 'O'
  EXPECT_EQ(move, 7);
}
