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
 *  @file    QLearning_test.cpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief
 *  This is a QLearning class test file.
 *  Test cases are written to ensure the implementation is correct. All test cases must pass.
 *  If any test case fails, please correct the corresponding function definition.
 *
 */

#include "QLearning.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

using std::string;
using std::map;

/**
 * @brief Shared pointer object of this class
 */
std::shared_ptr<QLearning> QLearningTestObject;

/**
 * @brief Test case for random function.
 */
TEST(QLearning, randomTest) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Call the random function
  int r = QLearningTestObject->random(0, 100);
  // Check if the the number lies within the range
  bool valid = false;
  if (r >= 0 && r <= 100) {
    valid = true;
  }
  EXPECT_TRUE(valid);
}

/**
 * @brief Test case for findValidMoves function.
 */
TEST(QLearning, findValidMovesTest) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Write possible states of the board
  string board = "  tt t  t";
  // Find the valid moves
  QLearningTestObject->findValidMoves(board);
  // Verify the valid moves
  bool valid = true;
  for (auto i : QLearningTestObject->validMoves) {
    if (board[i - 1] != ' ') {
      valid = false;
      break;
    }
  }
  // Expect all moves to be valid
  EXPECT_TRUE(valid);
}

/**
 * @brief Test case for addKey function.
 */
TEST(QLearning, addKeyTest) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  string stateKey = "XXOXOOXO X";
  // Call the addKey function and pass a stateKey
  QLearningTestObject->addKey(stateKey);
  // Check if valid moves are added and initialized in table
  bool valid = false;
  if (QLearningTestObject->table.find(stateKey)
      != QLearningTestObject->table.end()) {
    map<int, float> actionValue = QLearningTestObject->table[stateKey];
    if (actionValue.find(9) != actionValue.end()) {
      if (actionValue[9] == 1.0) {
        valid = true;
      }
    }
  }
  EXPECT_TRUE(valid);
}

/**
 * @brief Test case for chooseAction function for marker 'X'.
 */
TEST(QLearning, chooseActionTest1) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Set a key for marker 'X'
  string stateKey = "XXOXOO   X";
  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));
  QLearningTestObject->setEpsilon(-1.0);
  // Call the chooseAction function to select a move
  int move = QLearningTestObject->chooseAction(stateKey);
  // Expect the move is the highest action value pair for 'X'
  EXPECT_EQ(move, 9);
}

/**
 * @brief Test case for chooseAction function for marker 'O'.
 */
TEST(QLearning, chooseActionTest2) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));
  QLearningTestObject->setEpsilon(-1.0);
  // Call the chooseAction function to select a move
  int move = QLearningTestObject->chooseAction(stateKey);
  // Expect the move is the lowest action value pair for 'O'
  EXPECT_EQ(move, 7);
}

/**
 * @brief Test case for chooseAction function for epsilon = 1.
 */
TEST(QLearning, chooseActionTest3) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));
  QLearningTestObject->setEpsilon(1.0);
  // Call the chooseAction function to select a move
  int move = QLearningTestObject->chooseAction(stateKey);
  bool valid = false;
  if (move == 7 || move == 8 || move == 9) {
    valid = true;
  }
  // Expect the move to be between the valid moves
  EXPECT_TRUE(valid);
}

/**
 * @brief Test case for lowestQvalueAction function.
 */
TEST(QLearning, lowestQvalueActionTest1) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));
  // Call the lowestQvalueAction function to select a move
  int move = QLearningTestObject->lowestQvalueAction(stateKey);
  // Expect the move to be one with lowest value
  EXPECT_EQ(move, 7);
}

/**
 * @brief Test case for lowestQvalueAction function (Repeating values).
 */
TEST(QLearning, lowestQvalueActionTest2) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 1.0));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));
  // Call the lowestQvalueAction function to select a move
  int move = QLearningTestObject->lowestQvalueAction(stateKey);
  // Expect the move to be one with lowest value
  bool valid = false;
  if (move == 7 || move == 8) {
    valid = true;
  }
  EXPECT_TRUE(valid);
}

/**
 * @brief Test case for highestQvalueAction function.
 */
TEST(QLearning, highestQvalueActionTest1) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));
  // Call the highestQvalueAction function to select a move
  int move = QLearningTestObject->highestQvalueAction(stateKey);
  // Expect the move to be one with highest value
  EXPECT_EQ(move, 9);
}

/**
 * @brief Test case for highestQvalueAction function (Repeating values).
 */
TEST(QLearning, highestQvalueActionTest2) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 2.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));
  // Call the highestQvalueAction function to select a move
  int move = QLearningTestObject->highestQvalueAction(stateKey);
  // Expect the move to be one with highest value
  bool valid = false;
  if (move == 9 || move == 8) {
    valid = true;
  }
  EXPECT_TRUE(valid);
}

/**
 * @brief Test case for reinforcement function.
 */
TEST(QLearning, reinforcementTest) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Set a key to the board
  string stateKey = "X         X";
  QLearningTestObject->B.setBoard(stateKey.substr(0, 9));
  float reward = QLearningTestObject->reinforcement(stateKey);
  EXPECT_EQ(reward, 0);
  // Set a key for marker 'X' - X wins
  stateKey = "XXXOO    X";
  QLearningTestObject->B.setMarker('X');
  QLearningTestObject->B.setBoard(stateKey.substr(0, 9));
  reward = QLearningTestObject->reinforcement(stateKey);
  EXPECT_EQ(reward, 1.0);
  // Set a key for marker 'O' - O wins
  stateKey = "OOOXX X   O";
  QLearningTestObject->B.setMarker('O');
  QLearningTestObject->B.setBoard(stateKey.substr(0, 9));
  reward = QLearningTestObject->reinforcement(stateKey);
  EXPECT_EQ(reward, -1);
  // Set a key to draw the board
  stateKey = "XOXOOXXXOX";
  QLearningTestObject->count = 9;
  QLearningTestObject->B.setBoard(stateKey.substr(0, 9));
  reward = QLearningTestObject->reinforcement(stateKey);
  EXPECT_EQ(reward, 0.5);
}

/**
 * @brief Test case for lowestQvalue function.
 */
TEST(QLearning, lowestQvalueTest) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));
  // Call the lowestQvalue function to select a move
  float value = QLearningTestObject->lowestQvalue(stateKey);
  // Expect the move to be one with lowest value
  EXPECT_EQ(value, 0.5);
}

/**
 * @brief Test case for highestQvalue function.
 */
TEST(QLearning, highestQvalueTest) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));
  // Call the highestQvalue function to select a move
  float value = QLearningTestObject->highestQvalue(stateKey);
  // Expect the move to be one with lowest value
  EXPECT_EQ(value, 2.0);
}

/**
 * @brief Test case for updateQvalues function. (game over)
 */
TEST(QLearning, updateQvaluesTest1) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();

  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  int action = 7;
  string nextKey = "XXOXOOX  X";
  float reward = 1.0;

  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));

  QLearningTestObject->B.setMarker('X');
  QLearningTestObject->B.setBoard(nextKey.substr(0, 9));

  QLearningTestObject->updateQvalues(stateKey, action, nextKey, reward);
  // Expect the q value is updated
  float newValue = QLearningTestObject->table[stateKey][action];
  float expected = 0.65;
  bool valid = false;
  if (newValue == expected) {
    valid = true;
  }
  EXPECT_TRUE(valid);
}

/**
 * @brief Test case for updateQvalues function. (game not over)
 */
TEST(QLearning, updateQvaluesTest2) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();

  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  int action = 8;
  string nextKey = "XXOXOO X X";
  float reward = 0.0;

  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));

  // Add the valid moves in the Q table
  actionValue.clear();
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(nextKey, actionValue));

  QLearningTestObject->B.setMarker('X');
  QLearningTestObject->B.setBoard(nextKey.substr(0, 9));


  QLearningTestObject->updateQvalues(stateKey, action, nextKey, reward);
  // Expect the q value is updated
  float newValue = QLearningTestObject->table[stateKey][action];
  float expected = 0.835;
  bool valid = false;
  if (newValue == expected) {
    valid = true;
  }
  EXPECT_TRUE(valid);
}

/**
 * @brief Test case for updateQvalues function. (game not over)
 */
TEST(QLearning, updateQvaluesTest3) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();

  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  int action = 8;
  string nextKey = "XXOXOO X X";
  float reward = 0.0;

  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(8, 1.0));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));

  // Add the valid moves in the Q table
  actionValue.clear();
  actionValue.insert(std::make_pair(7, 0.5));
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(nextKey, actionValue));

  QLearningTestObject->B.setMarker('O');
  QLearningTestObject->B.setBoard(nextKey.substr(0, 9));

  QLearningTestObject->updateQvalues(stateKey, action, nextKey, reward);
  // Expect the q value is updated
  float newValue = QLearningTestObject->table[stateKey][action];
  float expected = 1.24;
  bool valid = false;
  if (newValue == expected) {
    valid = true;
  }
  EXPECT_TRUE(valid);
}

/**
 * @brief Test case for train function.
 */
TEST(QLearning, trainTest) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  QLearningTestObject->setEpochs(1);
  QLearningTestObject->testing = true;
  QLearningTestObject->train();
  EXPECT_GT(QLearningTestObject->table.size(), 1);
}

/**
 * @brief Test case for saveQTable function.
 */
TEST(QLearning, saveQTableTest) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  // Add the valid moves in the Q table
  std::map<int, float> actionValue;
  actionValue.insert(std::make_pair(9, 2.0));
  // Insert in the Q table
  QLearningTestObject->table.insert(std::make_pair(stateKey, actionValue));
  QLearningTestObject->testing = true;
  // Save the Q table
  QLearningTestObject->saveQTable();
  // Check if table got saved
  QLearningTestObject->table.clear();
  string line;
  string location = "../Qtable/Qtable.txt";
  std::ifstream myfile(location);
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      string state;
      state = line.substr(0, 10);
      int action;
      float value;
      map<int, float> actionValue;
      std::stringstream ss(line.substr(10, line.size() - 10));
      while (ss >> action >> value) {
        actionValue.insert(std::make_pair(action, value));
      }
      QLearningTestObject->table.insert(std::make_pair(state, actionValue));
    }
    myfile.close();
  }
  // Validate the contents
  bool valid = false;
  if (QLearningTestObject->table.find(stateKey)
      != QLearningTestObject->table.end()) {
    map<int, float> actionValue = QLearningTestObject->table[stateKey];
    if (actionValue.find(9) != actionValue.end()) {
      if (actionValue[9] == 2.0) {
        valid = true;
      }
    }
  }
  EXPECT_TRUE(valid);
}

/**
 * @brief Test case for loadQtable function.
 */
TEST(QLearning, loadQtableTest) {
  // Assign value to the shared pointer to the object
  QLearningTestObject = std::make_shared<QLearning>();
  QLearningTestObject->location = "../test/Qtable_test.txt";
  QLearningTestObject->testing = true;
  QLearningTestObject->loadQtable();
  // Validate the contents
  // Set a key for marker 'O'
  string stateKey = "XXOXOO   O";
  bool valid = false;
  if (QLearningTestObject->table.find(stateKey)
      != QLearningTestObject->table.end()) {
    map<int, float> actionValue = QLearningTestObject->table[stateKey];
    if (actionValue.find(9) != actionValue.end()) {
      if (actionValue[9] == 2.0) {
        valid = true;
      }
    }
  }
  EXPECT_TRUE(valid);
}

