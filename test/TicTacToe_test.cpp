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
 *  @brief
 *  This is a TicTacToe class test file.
 *  Test cases are written to ensure the implementation is correct. All test cases must pass.
 *  If any test case fails, please correct the corresponding function definition.
 *
 */

#include "TicTacToe.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include <memory>
#include "Board.hpp"
#include "Player.hpp"
#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"
#include "AIPlayer.hpp"

using std::string;

/**
 * @brief Shared pointer object of this class
 */
std::shared_ptr<TicTacToe> TicTacToeTestObject;

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

/**
 * @brief Mock class for RandomPlayer.
 */
class MockRandomPlayer : public RandomPlayer {
 public:
  MockRandomPlayer()
      : RandomPlayer() {
  }
  /**
   * @brief Mocks the input function
   */
  MOCK_METHOD0(input, int());
};

/**
 * @brief Mock class for HumanPlayer.
 */
class MockHumanPlayer : public HumanPlayer {
 public:
  MockHumanPlayer()
      : HumanPlayer() {
  }
  /**
   * @brief Mocks the input function
   */
  MOCK_METHOD0(input, int());
};

/**
 * @brief Mock class for AIPlayer.
 */
class MockAIPlayer : public AIPlayer {
 public:
  MockAIPlayer()
      : AIPlayer() {
  }
  /**
   * @brief Mocks the input function
   */
  MOCK_METHOD0(input, int());
};

/**
 * @brief Mock class for Board.
 */
class MockBoard : public Board {
 public:
  MockBoard()
      : Board() {
  }
  /**
   * @brief Mocks the updateBoard function
   */
  MOCK_METHOD1(updateBoard, void(int _));
  /**
   * @brief Mocks the toggleMarker function
   */
  MOCK_METHOD0(toggleMarker, void());
  /**
   * @brief Mocks the isWin function
   */
  MOCK_METHOD0(isWin, bool());
  /**
   * @brief Mocks the getEBoard function
   */
  MOCK_METHOD0(getEBoard, string());
};

/**
 * @brief Test case for startGame function. (Random vs Random)
 */
TEST(TicTacToe, startGameTest1) {
  // Assign value to the shared pointer to the object
  TicTacToeTestObject = std::make_shared<TicTacToe>();
  TicTacToeTestObject->testing = true;
  int i = 1;

  MockRandomPlayer rp1, rp2;
  // Mock input method to return position
  EXPECT_CALL(rp1, input()).Times(::testing::AtLeast(1)).WillRepeatedly(
      ::testing::Return(i++));
  EXPECT_CALL(rp2, input()).Times(::testing::AtLeast(1)).WillRepeatedly(
      ::testing::Return(i++));

  MockBoard mb;
  // Mock board functions used in startGame
  EXPECT_CALL(mb, toggleMarker()).Times(::testing::AtLeast(1));
  EXPECT_CALL(mb, updateBoard(::testing::_)).Times(::testing::AtLeast(1));
  EXPECT_CALL(mb, getEBoard()).Times(::testing::AtLeast(1)).WillRepeatedly(
      ::testing::Return("         "));
  // Mock isWin to return false for the first time and
  // true second time to end the game
  EXPECT_CALL(mb, isWin()).Times(::testing::AtLeast(1)).WillOnce(
      ::testing::Return(false)).WillOnce(::testing::Return(false))
      .WillRepeatedly(::testing::Return(true));

  Player *p1, *p2;
  p1 = &rp1;
  p2 = &rp2;
  mb.testing = true;
  p1->testing = true;
  p2->testing = true;
  TicTacToeTestObject->startGame(&mb, p1, p2);
  // Expect the countGames to be incremented
  EXPECT_GT(TicTacToeTestObject->countGames, 1);
}

/**
 * @brief Test case for startGame function. (Human vs Human)
 */
TEST(TicTacToe, startGameTest2) {
  // Assign value to the shared pointer to the object
  TicTacToeTestObject = std::make_shared<TicTacToe>();
  TicTacToeTestObject->testing = true;
  int i = 1;

  MockHumanPlayer hp1, hp2;
  // Mock input method to return position
  EXPECT_CALL(hp1, input()).Times(::testing::AtLeast(1)).WillRepeatedly(
      ::testing::Return(i++));
  EXPECT_CALL(hp2, input()).Times(::testing::AtLeast(1)).WillRepeatedly(
      ::testing::Return(i++));

  MockBoard mb;
  // Mock board functions used in startGame
  EXPECT_CALL(mb, toggleMarker()).Times(::testing::AtLeast(1));
  EXPECT_CALL(mb, updateBoard(::testing::_)).Times(::testing::AtLeast(1));
  EXPECT_CALL(mb, getEBoard()).Times(::testing::AtLeast(1)).WillRepeatedly(
      ::testing::Return("         "));
  // Mock isWin to return false for the first time and
  // true second time to end the game
  EXPECT_CALL(mb, isWin()).Times(::testing::AtLeast(1)).WillOnce(
      ::testing::Return(false)).WillOnce(::testing::Return(false))
      .WillRepeatedly(::testing::Return(true));

  Player *p1, *p2;
  p1 = &hp1;
  p2 = &hp2;
  mb.testing = true;
  p1->testing = true;
  p2->testing = true;
  TicTacToeTestObject->startGame(&mb, p1, p2);
  // Expect the countGames to be incremented
  EXPECT_GT(TicTacToeTestObject->countGames, 1);
}

/**
 * @brief Test case for startGame function. (Human vs Random)
 */
TEST(TicTacToe, startGameTest3) {
  // Assign value to the shared pointer to the object
  TicTacToeTestObject = std::make_shared<TicTacToe>();
  TicTacToeTestObject->testing = true;
  int i = 1;

  MockHumanPlayer hp;
  MockRandomPlayer rp;
  // Mock input method to return position
  EXPECT_CALL(hp, input()).Times(::testing::AtLeast(1)).WillRepeatedly(
      ::testing::Return(i++));
  EXPECT_CALL(rp, input()).Times(::testing::AtLeast(1)).WillRepeatedly(
      ::testing::Return(i++));

  MockBoard mb;
  // Mock board functions used in startGame
  EXPECT_CALL(mb, toggleMarker()).Times(::testing::AtLeast(1));
  EXPECT_CALL(mb, updateBoard(::testing::_)).Times(::testing::AtLeast(1));
  EXPECT_CALL(mb, getEBoard()).Times(::testing::AtLeast(1)).WillRepeatedly(
      ::testing::Return("         "));
  // Mock isWin to return false for the first time and
  // true second time to end the game
  EXPECT_CALL(mb, isWin()).Times(::testing::AtLeast(1)).WillOnce(
      ::testing::Return(false)).WillOnce(::testing::Return(false))
      .WillRepeatedly(::testing::Return(true));

  Player *p1, *p2;
  p1 = &hp;
  p2 = &rp;
  mb.testing = true;
  p1->testing = true;
  p2->testing = true;
  TicTacToeTestObject->startGame(&mb, p1, p2);
  // Expect the countGames to be incremented
  EXPECT_GT(TicTacToeTestObject->countGames, 1);
}

/**
 * @brief Test case for startGame function. (Human1 vs Human2 - H1 win)
 */
TEST(TicTacToe, startGameTest4) {
  // Assign value to the shared pointer to the object
  TicTacToeTestObject = std::make_shared<TicTacToe>();
  TicTacToeTestObject->testing = true;

  MockHumanPlayer hp1, hp2;
  // Mock input method to return position
  EXPECT_CALL(hp1, input()).WillOnce(::testing::Return(1)).WillOnce(
      ::testing::Return(3)).WillOnce(::testing::Return(5)).WillOnce(
      ::testing::Return(7));
  EXPECT_CALL(hp2, input()).WillOnce(::testing::Return(2)).WillOnce(
      ::testing::Return(4)).WillOnce(::testing::Return(6));

  Board b;

  Player *p1, *p2;
  p1 = &hp1;
  p2 = &hp2;
  b.testing = true;
  p1->testing = true;
  p2->testing = true;
  TicTacToeTestObject->startGame(&b, p1, p2);
  // Expect the countGames to be incremented
  EXPECT_EQ(TicTacToeTestObject->countGames, 7);
  // Expect board to be not empty
  string board = "XOXOXOX  ";
  EXPECT_EQ(b.getEBoard(), board);
}

/**
 * @brief Test case for startGame function. (Human1 vs Human2 - H2 win)
 */
TEST(TicTacToe, startGameTest5) {
  // Assign value to the shared pointer to the object
  TicTacToeTestObject = std::make_shared<TicTacToe>();
  TicTacToeTestObject->testing = true;

  MockHumanPlayer hp1, hp2;
  // Mock input method to return position
  EXPECT_CALL(hp1, input()).WillOnce(::testing::Return(1)).WillOnce(
      ::testing::Return(2)).WillOnce(::testing::Return(4));
  EXPECT_CALL(hp2, input()).WillOnce(::testing::Return(3)).WillOnce(
      ::testing::Return(5)).WillOnce(::testing::Return(7));

  Board b;

  Player *p1, *p2;
  p1 = &hp1;
  p2 = &hp2;
  b.testing = true;
  p1->testing = true;
  p2->testing = true;
  TicTacToeTestObject->startGame(&b, p1, p2);
  // Expect the countGames to be incremented
  EXPECT_EQ(TicTacToeTestObject->countGames, 6);
  // Expect board to be not empty
  string board = "XXOXO O  ";
  EXPECT_EQ(b.getEBoard(), board);
}

/**
 * @brief Test case for startGame function. (Human1 vs Human2 - Draw)
 */
TEST(TicTacToe, startGameTest6) {
  // Assign value to the shared pointer to the object
  TicTacToeTestObject = std::make_shared<TicTacToe>();
  TicTacToeTestObject->testing = true;

  MockHumanPlayer hp1, hp2;
  // Mock input method to return position
  EXPECT_CALL(hp1, input()).WillOnce(::testing::Return(5)).WillOnce(
      ::testing::Return(2)).WillOnce(::testing::Return(4)).WillOnce(
      ::testing::Return(3)).WillOnce(::testing::Return(9));
  EXPECT_CALL(hp2, input()).WillOnce(::testing::Return(1)).WillOnce(
      ::testing::Return(8)).WillOnce(::testing::Return(6)).WillOnce(
      ::testing::Return(7));

  Board b;

  Player *p1, *p2;
  p1 = &hp1;
  p2 = &hp2;
  b.testing = true;
  p1->testing = true;
  p2->testing = true;
  TicTacToeTestObject->startGame(&b, p1, p2);
  // Expect the countGames to be incremented
  EXPECT_EQ(TicTacToeTestObject->countGames, 9);
  // Expect board to be not empty
  string board = "OXXXXOOOX";
  EXPECT_EQ(b.getEBoard(), board);
}

/**
 * @brief Test case for startGame function. (Human vs AI)
 */
TEST(TicTacToe, startGameTest7) {
  // Assign value to the shared pointer to the object
  TicTacToeTestObject = std::make_shared<TicTacToe>();
  TicTacToeTestObject->testing = true;
  int i = 1;

  MockHumanPlayer hp;
  MockAIPlayer AI;
  // Mock input method to return position
  EXPECT_CALL(hp, input()).Times(::testing::AtLeast(1)).WillRepeatedly(
      ::testing::Return(i++));
  EXPECT_CALL(AI, input()).Times(::testing::AtLeast(1)).WillRepeatedly(
      ::testing::Return(i++));

  MockBoard mb;
  // Mock board functions used in startGame
  EXPECT_CALL(mb, toggleMarker()).Times(::testing::AtLeast(1));
  EXPECT_CALL(mb, updateBoard(::testing::_)).Times(::testing::AtLeast(1));
  EXPECT_CALL(mb, getEBoard()).Times(::testing::AtLeast(1)).WillRepeatedly(
      ::testing::Return("         "));
  // Mock isWin to return false for the first time and
  // true second time to end the game
  EXPECT_CALL(mb, isWin()).Times(::testing::AtLeast(1)).WillOnce(
      ::testing::Return(false)).WillOnce(::testing::Return(false))
      .WillRepeatedly(::testing::Return(true));

  Player *p1, *p2;
  p1 = &hp;
  p2 = &AI;
  mb.testing = true;
  p1->testing = true;
  p2->testing = true;
  TicTacToeTestObject->startGame(&mb, p1, p2);
  // Expect the countGames to be incremented
  EXPECT_GT(TicTacToeTestObject->countGames, 1);
}

/**
 * @brief Test case for testAccuracy function. (Human vs Human - H1 wins)
 */
TEST(TicTacToe, testAccuracyTest1) {
  // Assign value to the shared pointer to the object
  TicTacToeTestObject = std::make_shared<TicTacToe>();
  TicTacToeTestObject->testing = true;

  MockHumanPlayer hp1, hp2;
  // Mock input method to return position
  EXPECT_CALL(hp1, input()).WillOnce(::testing::Return(1)).WillOnce(
      ::testing::Return(3)).WillOnce(::testing::Return(5)).WillOnce(
      ::testing::Return(7));
  EXPECT_CALL(hp2, input()).WillOnce(::testing::Return(2)).WillOnce(
      ::testing::Return(4)).WillOnce(::testing::Return(6));

  Board b;

  Player *p1, *p2;
  p1 = &hp1;
  p2 = &hp2;
  b.testing = true;
  p1->testing = true;
  p2->testing = true;
  TicTacToeTestObject->tests = 1;
  TicTacToeTestObject->testAccuracy(&b, p1, p2);
  // Expect the p1 to win
  EXPECT_EQ(TicTacToeTestObject->win, 1);
  EXPECT_EQ(TicTacToeTestObject->draw, 0);
}

/**
 * @brief Test case for testAccuracy function. (Human1 vs Human2 - Draw)
 */
TEST(TicTacToe, testAccuracyTest2) {
  // Assign value to the shared pointer to the object
  TicTacToeTestObject = std::make_shared<TicTacToe>();
  TicTacToeTestObject->testing = true;

  MockHumanPlayer hp1, hp2;
  // Mock input method to return position
  EXPECT_CALL(hp1, input()).WillOnce(::testing::Return(5)).WillOnce(
      ::testing::Return(2)).WillOnce(::testing::Return(4)).WillOnce(
      ::testing::Return(3)).WillOnce(::testing::Return(9));
  EXPECT_CALL(hp2, input()).WillOnce(::testing::Return(1)).WillOnce(
      ::testing::Return(8)).WillOnce(::testing::Return(6)).WillOnce(
      ::testing::Return(7));

  Board b;

  Player *p1, *p2;
  p1 = &hp1;
  p2 = &hp2;
  b.testing = true;
  p1->testing = true;
  p2->testing = true;
  TicTacToeTestObject->tests = 1;
  TicTacToeTestObject->testAccuracy(&b, p1, p2);
  // Expect the p1 to draw
  EXPECT_EQ(TicTacToeTestObject->win, 0);
  EXPECT_EQ(TicTacToeTestObject->draw, 1);
}

/**
 * @brief Test case for startGame function. (Human1 vs Human2 - H2 win)
 */
TEST(TicTacToe, testAccuracyTest3) {
  // Assign value to the shared pointer to the object
  TicTacToeTestObject = std::make_shared<TicTacToe>();
  TicTacToeTestObject->testing = true;

  MockHumanPlayer hp1, hp2;
  // Mock input method to return position
  EXPECT_CALL(hp1, input()).WillOnce(::testing::Return(1)).WillOnce(
      ::testing::Return(2)).WillOnce(::testing::Return(4));
  EXPECT_CALL(hp2, input()).WillOnce(::testing::Return(3)).WillOnce(
      ::testing::Return(5)).WillOnce(::testing::Return(7));
  Board b;

  Player *p1, *p2;
  p1 = &hp1;
  p2 = &hp2;
  b.testing = true;
  p1->testing = true;
  p2->testing = true;
  TicTacToeTestObject->tests = 1;
  TicTacToeTestObject->testAccuracy(&b, p1, p2);
  // Expect the p1 to loose
  EXPECT_EQ(TicTacToeTestObject->win, 0);
  EXPECT_EQ(TicTacToeTestObject->draw, 0);
}
