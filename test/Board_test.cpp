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
 *  @file    Board_test.cpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief Coding challenge by Plus One Robotics.
 *
 *  @section DESCRIPTION
 *  This is a Board class test file.
 *  Test cases are written to ensure the implementation is correct. All test cases must pass.
 *  If any test case fails, please correct the corresponding function definition.
 */

#include "Board.hpp"
#include <gtest/gtest.h>
#include <memory>

std::shared_ptr<Board> BoardTestObject;

/**
 * @brief Test case for clearBoard function.
 */
TEST(Board, clearBoardTest) {
  // Assign value to the shared pointer to the object
  BoardTestObject = std::make_shared<Board>();
  // Call the clearBoard function
  BoardTestObject->clearBoard();
  // Verify whether all cells of board are blank
  bool empty = true;
  for (int i = 0; i < 9; i++) {
    if (BoardTestObject->getBoard(i) != ' ') {
      empty = false;
      break;
    }
  }
  // Expect true if all cells are blank
  EXPECT_TRUE(empty);
}

/**
 * @brief Test case for updateBoard function
 */
TEST(Board, updateBoardTest) {
  // Assign value to the shared pointer to the object
  BoardTestObject = std::make_shared<Board>();
  // Make all the cells of board blank
  const char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
  BoardTestObject->setBoard(board);
  // Assign a character to the maker
  BoardTestObject->setMarker('t');
  // Iterate over each position on the board
  bool update = true;
  for (int i = 1; i <= 9; i++) {
    // Call the updateBoard function
    BoardTestObject->updateBoard(i);
    // Verify if marker is set correctly
    if (BoardTestObject->getBoard(i - 1) != 't') {
      update = false;
      break;
    }
  }
  // Expect true if all cells are updated correctly
  EXPECT_TRUE(update);
}

/**
 * @brief Test case for toggleMarker function
 */
TEST(Board, toggleMarkerTest) {
  // Assign value to the shared pointer to the object
  BoardTestObject = std::make_shared<Board>();
  // Assign 'X' character to the maker
  BoardTestObject->setMarker('X');
  // Call the toggleMarker function
  BoardTestObject->toggleMarker();
  // Expect the marker value has changed to 'O'
  EXPECT_EQ(BoardTestObject->getMarker(), 'O');
  // Assign 'O' character to the maker
  BoardTestObject->setMarker('O');
  // Call the toggleMarker function
  BoardTestObject->toggleMarker();
  // Expect the marker value has changed to 'X'
  EXPECT_EQ(BoardTestObject->getMarker(), 'X');
}

/**
 * @brief Test case for isWin function
 */
TEST(Board, isWinTest1) {
  // Assign value to the shared pointer to the object
  BoardTestObject = std::make_shared<Board>();
  // Write all the winning states of the board and check is win
  BoardTestObject->setMarker('t');
  const char board[9] = { 't', 't', 't', ' ', ' ', ' ', ' ', ' ', ' ' };
  BoardTestObject->setBoard(board);
  EXPECT_TRUE(BoardTestObject->isWin());
}

/**
 * @brief Test case for isWin function
 */
TEST(Board, isWinTest2) {
  // Assign value to the shared pointer to the object
  BoardTestObject = std::make_shared<Board>();
  // Write all the winning states of the board and check is win
  BoardTestObject->setMarker('t');
  const char board[9] = { ' ', ' ', ' ', 't', 't', 't', ' ', ' ', ' ' };
  BoardTestObject->setBoard(board);
  EXPECT_TRUE(BoardTestObject->isWin());
}

/**
 * @brief Test case for isWin function
 */
TEST(Board, isWinTest3) {
  // Assign value to the shared pointer to the object
  BoardTestObject = std::make_shared<Board>();
  // Write all the winning states of the board and check is win
  BoardTestObject->setMarker('t');
  const char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', 't', 't', 't' };
  BoardTestObject->setBoard(board);
  EXPECT_TRUE(BoardTestObject->isWin());
}

/**
 * @brief Test case for isWin function
 */
TEST(Board, isWinTest4) {
  // Assign value to the shared pointer to the object
  BoardTestObject = std::make_shared<Board>();
  // Write all the winning states of the board and check is win
  BoardTestObject->setMarker('t');
  const char board[9] = { 't', ' ', ' ', 't', ' ', ' ', 't', ' ', ' ' };
  BoardTestObject->setBoard(board);
  EXPECT_TRUE(BoardTestObject->isWin());
}

/**
 * @brief Test case for isWin function
 */
TEST(Board, isWinTest5) {
  // Assign value to the shared pointer to the object
  BoardTestObject = std::make_shared<Board>();
  // Write all the winning states of the board and check is win
  BoardTestObject->setMarker('t');
  const char board[9] = { ' ', 't', ' ', ' ', 't', ' ', ' ', 't', ' ' };
  BoardTestObject->setBoard(board);
  EXPECT_TRUE(BoardTestObject->isWin());
}

/**
 * @brief Test case for isWin function
 */
TEST(Board, isWinTest6) {
  // Assign value to the shared pointer to the object
  BoardTestObject = std::make_shared<Board>();
  // Write all the winning states of the board and check is win
  BoardTestObject->setMarker('t');
  const char board[9] = { ' ', ' ', 't', ' ', ' ', 't', ' ', ' ', 't' };
  BoardTestObject->setBoard(board);
  EXPECT_TRUE(BoardTestObject->isWin());
}

/**
 * @brief Test case for isWin function
 */
TEST(Board, isWinTest7) {
  // Assign value to the shared pointer to the object
  BoardTestObject = std::make_shared<Board>();
  // Write all the winning states of the board and check is win
  BoardTestObject->setMarker('t');
  const char board[9] = { 't', ' ', ' ', ' ', 't', ' ', ' ', ' ', 't' };
  BoardTestObject->setBoard(board);
  EXPECT_TRUE(BoardTestObject->isWin());
}

/**
 * @brief Test case for isWin function
 */
TEST(Board, isWinTest8) {
  // Assign value to the shared pointer to the object
  BoardTestObject = std::make_shared<Board>();
  // Write all the winning states of the board and check is win
  BoardTestObject->setMarker('t');
  const char board[9] = { ' ', ' ', 't', ' ', 't', ' ', 't', ' ', ' ' };
  BoardTestObject->setBoard(board);
  EXPECT_TRUE(BoardTestObject->isWin());
}
