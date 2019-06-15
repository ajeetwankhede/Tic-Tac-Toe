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
 *  @file    main.cpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief Coding challenge by Plus One Robotics
 *
 *  @section DESCRIPTION
 *  This is the main file.
 *  Object of class TicTacToe is created and startGame() is called.
 */

#include <iostream>
#include <string>
#include "TicTacToe.hpp"
#include "Board.hpp"
#include "HumanPlayer.hpp"
#include "RandomPlayer.hpp"
#include "Player.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
  cout << "Welcome to Tic Tac Toe!!" << endl;
  int choice;
  char play = 'Y';
  while (play == 'Y' || play == 'y') {
    cout
        << "Choose type of game you want to play:\n"
         << "1. Human vs Human\n"
         << "2. Human vs Computer\n" << "3. Computer vs Computer"
        << endl;
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3) {
      cout << "Please enter a valid choice: " << endl;
      cin >> choice;
    }
    TicTacToe T;
    Board B;
    Player *p1, *p2;
    std::string name;
    switch (choice) {
      case 1: {
        HumanPlayer hp1, hp2;
        p1 = &hp1;
        p2 = &hp2;
        cout << "Enter player1 name: " << endl;
        cin >> name;
        p1->setName(name);
        cout << "Enter player2 name: " << endl;
        cin >> name;
        p2->setName(name);
        T.startGame(&B, p1, p2);
        break;
      }
      case 2: {
        HumanPlayer hp;
        RandomPlayer rp;
        p1 = &hp;
        p2 = &rp;
        cout << "Enter player name: " << endl;
        cin >> name;
        p1->setName(name);
        p2->setName("Random");
        T.startGame(&B, p1, p2);
        break;
      }
      case 3: {
        RandomPlayer rp1, rp2;
        p1 = &rp1;
        p2 = &rp2;
        p1->setName("Random1");
        p2->setName("Random2");
        T.startGame(&B, p1, p2);
        break;
      }
    }
    cout << "Want to play another game? (Y/N): " << endl;
    cin >> play;
  }
  cout << "Thank you for playing!!" << endl;
  return 0;
}
