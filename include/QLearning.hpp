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
 *  @file    QLearning.hpp
 *  @author  Ajeet Wankhede
 *  @date    06/16/2019
 *  @version 1.0
 *
 *  @brief
 *  This is a QLearning class header file.
 *  This class is used to train the AI agent using Q learning.
 *
 */

#ifndef INCLUDE_QLEARNING_HPP_
#define INCLUDE_QLEARNING_HPP_

#include <map>
#include <string>
#include <vector>
#include "Board.hpp"

class QLearning {
  /**
   *   @brief Stores the learning rate
   */
  float learningRate;
  /**
   *   @brief Stores the discount factor
   */
  float discount;
  /**
   *   @brief Stores the number of epochs
   */
  int epochs;
  /**
   *   @brief Stores the value of epsilon used for exploration/exploitation
   */
  float epsilon;

 public:
  /**
   *   @brief Default constructor for QLearning.
   */
  QLearning()
  : learningRate(0.3),
        discount(0.9),
        epochs(200000),
        count(0),
        epsilon(0.9),
        testing(false),
  location("../Qtable/Qtable.txt") {}
  /**
   *   @brief Default constructor for QLearning.
   */
  virtual ~QLearning();
  /**
   *   @brief Call this function to train the AI agent.
   */
  void train();
  /**
   *   @brief The function updates the Q values in the
   *   table using Bellman equation.
   *   @param stateKey a string of current state
   *   @param action an integer of selected action
   *   @param nextKey a string of next state
   *   @param reward a float specifying the reward for the selected action
   */
  void updateQvalues(std::string stateKey, int action, std::string nextKey,
                     float reward);
  /**
   *   @brief Add the given stateKey in the Q table.
   *   @param stateKey a string (key) to be added.
   */
  void addKey(std::string stateKey);
  /**
   *   @brief Chooses the action for the player.
   *   @param stateKey a string of current state and marker
   *   @return Chosen move
   */
  int chooseAction(std::string stateKey);
  /**
   *   @brief Decides the reward for given stateKey.
   *   @param nextKey a string of key in the Q table
   *   @return Reward
   */
  float reinforcement(std::string nextKey);
  /**
   *   @brief Selects the lowest value for the given key in the Q table.
   *   @param nextKey a string of key in the Q table
   *   @return Lowest Q value at nextKey
   */
  float lowestQvalue(std::string nextKey);
  /**
   *   @brief Selects the highest value for the given key in the Q table.
   *   @param nextKey a string of key in the Q table
   *   @return highest Q value at nextKey
   */
  float highestQvalue(std::string nextKey);
  /**
   *   @brief Saves the Q table dictionary in a text file.
   */
  void saveQTable();
  /**
   *   @brief Selects the action corresponding to lowest value for
   *   the given key in the Q table.
   *   @param stateKey a string of key in the Q table
   *   @return Action corresponding to lowest Q value at stateKey
   */
  int lowestQvalueAction(std::string stateKey);
  /**
   *   @brief Selects the action corresponding to highest value for
   *   the given key in the Q table.
   *   @param stateKey a string of key in the Q table
   *   @return Action corresponding to highest Q value at stateKey
   */
  int highestQvalueAction(std::string stateKey);
  /**
   *   @brief Loads the Q table from a text file in a dictionary.
   *   the given key in the Q table.
   */
  void loadQtable();
  /**
   *   @brief Finds the moves available for the player.
   *   @param board a string of the board values.
   */
  void findValidMoves(std::string board);
  /**
   *   @brief Returns a random number within the given range
   *   @param start an integer stating start of the range
   *   @param end an integer stating end of the range
   *   @return The generated random number
   */
  int random(int start, int end);
  /**
   *   @brief Sets the value of epsilon.
   *   @param e a float
   */
  void setEpsilon(float e);
  /**
   *   @brief Sets the value of epochs.
   *   @param e an integer
   */
  void setEpochs(int e);
  /**
   *   @brief Object of class Board
   */
  Board B;
  /**
   *   @brief Stores the valid moves
   */
  std::vector<int> validMoves;
  /**
   *   @brief Stores the Q table in form of dictionary
   */
  std::map<std::string, std::map<int, float>> table;
  /**
   *   @brief Counts the number of steps taken in a game
   */
  int count;
  /**
   *   @brief true if testing else false
   */
  bool testing;
  /**
   *   @brief Stores the path to save/load Q table
   */
  std::string location;
};

#endif  // INCLUDE_QLEARNING_HPP_
