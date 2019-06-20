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
 *  @file    RandomPlayer_test.cpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief
 *  This is a RandomPlayer class test file.
 *  Test cases are written to ensure the implementation is correct. All test cases must pass.
 *  If any test case fails, please correct the corresponding function definition.
 *
 */

#include "RandomPlayer.hpp"
#include <gtest/gtest.h>

/**
 * @brief Test case for input function.
 */
TEST(RandomPlayer, inputTest) {
  // Create an object of class RandomPlayer
  RandomPlayer RandomPlayerTestObject;
  // Add valid moves
  RandomPlayerTestObject.validMoves = {1, 2, 4, 6, 3, 7};
  // Call the input function to randomly select a move
  int move = RandomPlayerTestObject.input();
  // Check if the selected move lie within the validMoves
  bool valid = false;
  for (auto i : RandomPlayerTestObject.validMoves) {
    if (i == move) {
      valid = true;
      break;
    }
  }
  // Expect the move is chosen from the validMoves
  EXPECT_TRUE(valid);
}
