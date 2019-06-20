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
 *  @file    Player_test.cpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief
 *  This is a Player class test file.
 *  Test cases are written to ensure the implementation is correct. All test cases must pass.
 *  If any test case fails, please correct the corresponding function definition.
 *
 */

#include "Player.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <memory>
#include <sstream>

using std::string;

/**
 * @brief Shared pointer object of this class
 */
std::shared_ptr<Player> PlayerTestObject;

/**
 * @brief Test case for findValidMoves function.
 */
TEST(Player, findValidMovesTest) {
  // Assign value to the shared pointer to the object
  PlayerTestObject = std::make_shared<Player>();
  PlayerTestObject->testing = true;
  // Write possible states of the board
  string board = "  tt t  t";
  // Find the valid moves
  PlayerTestObject->findValidMoves(board);
  // Verify the valid moves
  bool valid = true;
  for (auto i : PlayerTestObject->validMoves) {
    if (board[i - 1] != ' ') {
      valid = false;
      break;
    }
  }
  // Expect all moves to be valid
  EXPECT_TRUE(valid);
}

/**
 * @brief Test case for displayValidMoves function with there are valid moves.
 */
TEST(Player, displayValidMovesTest1) {
  // Assign value to the shared pointer to the object
  PlayerTestObject = std::make_shared<Player>();
  PlayerTestObject->testing = true;
  std::stringstream ss;
  PlayerTestObject->validMoves.push_back(1);
  ss << "Moves remaining: 1" << std::endl;
  EXPECT_EQ(ss.str(), PlayerTestObject->displayValidMoves());
}

/**
 * @brief Test case for displayValidMoves function when there are no valid moves.
 */
TEST(Player, displayValidMovesTest2) {
  // Assign value to the shared pointer to the object
  PlayerTestObject = std::make_shared<Player>();
  PlayerTestObject->testing = true;
  std::stringstream ss;
  PlayerTestObject->validMoves.clear();
  ss << "No moves left." << std::endl;
  EXPECT_EQ(ss.str(), PlayerTestObject->displayValidMoves());
}

/**
 * @brief Test case for checkMove function when moves are within range 1-9.
 */
TEST(Player, checkMoveTest1) {
  // Assign value to the shared pointer to the object
  PlayerTestObject = std::make_shared<Player>();
  PlayerTestObject->testing = true;
  // Assign a state to the board
  string board = "  tt t  t";
  PlayerTestObject->currentBoard = board;
  for (int i = 1; i <= 9; i++) {
    if (board[i - 1] == ' ') {
      // Expect pos to be valid
      EXPECT_TRUE(PlayerTestObject->checkMove(i));
    } else {
      // Expect pos to be invalid
      EXPECT_FALSE(PlayerTestObject->checkMove(i));
    }
  }
}

/**
 * @brief Test case for checkMove function when moves are outside range 1-9.
 */
TEST(Player, checkMoveTest2) {
  // Assign value to the shared pointer to the object
  PlayerTestObject = std::make_shared<Player>();
  PlayerTestObject->testing = true;
  // Assign a state to the board
  string board = "  tt t  t";
  PlayerTestObject->currentBoard = board;
  // Expect pos to be invalid
  EXPECT_FALSE(PlayerTestObject->checkMove(10));
}

/**
 * @brief Test case for checkMove function.
 */
TEST(Player, inputTest) {
  // Assign value to the shared pointer to the object
  PlayerTestObject = std::make_shared<Player>();
  PlayerTestObject->testing = true;
  EXPECT_TRUE(PlayerTestObject->input());
}
