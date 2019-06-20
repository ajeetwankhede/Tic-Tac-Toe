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
 *  @file    QLearning.cpp
 *  @author  Ajeet Wankhede
 *  @date    06/16/2019
 *  @version 1.0
 *
 *  @brief
 *  This is a QLearning class source file.
 *  This class is used to train the AI agent using Q learning.
 *
 */

#include "QLearning.hpp"
#include <string>
#include <map>
#include <random>
#include <fstream>
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::string;

QLearning::~QLearning() {
}

void QLearning::setEpsilon(float e) {
  // Set the value of epsilon
  epsilon = e;
}

void QLearning::setEpochs(int e) {
  // Set the value of epsilon
  epochs = e;
}

void QLearning::findValidMoves(string board) {
  // Find the moves which are left to be played and
  // store the positions in validMoves
  validMoves.clear();
  for (int i = 1; i <= 9; i++) {
    if (board[i - 1] == ' ') {
      validMoves.push_back(i);
    }
  }
}

int QLearning::random(int start, int end) {
  // Generate a random moves from the valid moves
  std::random_device rd;  // obtain a random number from hardware
  std::mt19937 rng(rd());  // seed the generator
  std::uniform_int_distribution<> dist(start, end);  // define the range
  int index = dist(rng);
  return index;
}

void QLearning::addKey(string stateKey) {
  findValidMoves(stateKey.substr(0, 9));
  map<int, float> actionValue;
  if (validMoves.size() > 0) {
    for (auto i : validMoves) {
      float value = 1.0;
      actionValue.insert(std::make_pair(i, value));
    }
    table.insert(std::make_pair(stateKey, actionValue));
  }
}

int QLearning::chooseAction(string stateKey) {
  int action = 0;
  float prob = random(0, 100) / 100.0;
  if (prob < epsilon) {
    findValidMoves(stateKey.substr(0, 9));
    int index = random(0, validMoves.size() - 1);
    action = validMoves[index];
  } else {
    if (stateKey[9] == 'X') {
      action = highestQvalueAction(stateKey);
    } else if (stateKey[9] == 'O') {
      action = lowestQvalueAction(stateKey);
    }
  }
  return action;
}

int QLearning::lowestQvalueAction(std::string stateKey) {
  map<int, float> actionValue = table[stateKey];
  int minAction;
  float minValue = lowestQvalue(stateKey);
  vector<int> actionSet;
  for (auto it : actionValue) {
    if (it.second == minValue) {
      actionSet.push_back(it.first);
    }
  }
  if (actionSet.size() > 1) {
    int index = random(0, actionSet.size() - 1);
    minAction = actionSet[index];
  } else {
    minAction = actionSet[0];
  }
  return minAction;
}

int QLearning::highestQvalueAction(std::string stateKey) {
  map<int, float> actionValue = table[stateKey];
  int maxAction;
  float maxValue = highestQvalue(stateKey);
  vector<int> actionSet;
  for (auto it : actionValue) {
    if (it.second == maxValue) {
      actionSet.push_back(it.first);
    }
  }
  if (actionSet.size() > 1) {
    int index = random(0, actionSet.size() - 1);
    maxAction = actionSet[index];
  } else {
    maxAction = actionSet[0];
  }
  return maxAction;
}

float QLearning::reinforcement(string nextKey) {
  string state = nextKey.substr(0, 9);
  float reward = 0.0;
  if (B.isWin()) {
    if (B.getMarker() == 'X')
      reward = 1.0;
    else if (B.getMarker() == 'O')
      reward = -1.0;
  } else if (count == 9) {
    reward = 0.5;
  }
  return reward;
}

float QLearning::lowestQvalue(string nextKey) {
  map<int, float> actionValue = table[nextKey];
  float minValue = actionValue.begin()->second;
  for (auto it : actionValue) {
    if (minValue > it.second) {
      minValue = it.second;
    }
  }
  return minValue;
}

float QLearning::highestQvalue(string nextKey) {
  map<int, float> actionValue = table[nextKey];
  float maxValue = actionValue.begin()->second;
  for (auto it : actionValue) {
    if (maxValue < it.second) {
      maxValue = it.second;
    }
  }
  return maxValue;
}

void QLearning::updateQvalues(string stateKey, int action, string nextKey,
                              float reward) {
  float expected = 0.0;
  if (count == 9 || B.isWin()) {
    expected = reward;
  } else {
    if (B.getMarker() == 'X') {
      expected = reward + discount * lowestQvalue(nextKey);
    } else {
      expected = reward + discount * highestQvalue(nextKey);
    }
  }

  float change = learningRate * (expected - table[stateKey][action]);
  table[stateKey][action] += change;
}

void QLearning::train() {
  B.testing = true;
  if (!testing)
    cout << "Training the agent\n";
  int games = 0;
  while (games < epochs) {
    B.clearBoard();
    string state = B.getEBoard();
    count = 0;
    while (count < 9) {
      count++;
      string stateKey = state + B.getMarker();
      if (table.find(stateKey) == table.end()) {
        addKey(stateKey);
      }
      int action = chooseAction(stateKey);
      B.updateBoard(action);
      string nextState = B.getEBoard();
      char marker = 'X';
      if (B.getMarker() == 'X') {
        marker = 'O';
      }
      string nextKey = nextState + marker;
      if (table.find(nextKey) == table.end()) {
        addKey(nextKey);
      }
      float reward = reinforcement(nextKey);
      updateQvalues(stateKey, action, nextKey, reward);
      if (B.isWin()) {
        B.toggleMarker();
        break;
      } else {
        B.toggleMarker();
        state = nextState;
      }
  }
    games++;
  }
  if (!testing) {
    cout << "Training over\n";
    cout << "Rows in Qtable: " << table.size() << endl;
    saveQTable();
  }
}

void QLearning::saveQTable() {
  std::ofstream myFile;
  myFile.open(location);
  for (auto it : table) {
    myFile << it.first << ' ';
    for (auto t : it.second) {
      myFile << t.first << ' ' << t.second << ' ';
    }
    myFile << endl;
  }
  myFile.close();
  if (!testing)
    cout << "Qtable has been saved at: " << location << endl;
}

void QLearning::loadQtable() {
  table.clear();
  string line;
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
      table.insert(make_pair(state, actionValue));
    }
    myfile.close();
    if (!testing)
      cout << "Qtable loaded successfully!\n";
  } else {
    cout << "Unable to open file.\n";
  }
}
