# TicTacToe
[![Build Status](https://travis-ci.com/ajeetwankhede/Tic-Tac-Toe.svg?token=PaB15bgFhTxvmjf14qhk&branch=master)](https://travis-ci.com/ajeetwankhede/Tic-Tac-Toe)

---

## Project Overview

The task is to build an AI agent to learn to play Tic Tac Toe game and to implement object oriented programming concepts.

## Breif about Tic Tac Toe ([wikipedia](https://en.wikipedia.org/wiki/Tic-tac-toe))

Tic-tac-toe (American English), noughts and crosses (British English), or Xs and Os is a paper-and-pencil game for two players, X and O, who take turns marking the spaces in a 3×3 grid. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row first wins the game.

<p align="center">
<img src="/images/Tic_tac_toe.png">
</p>

## Breif about AI agent

In this project Q learning is implemented to train an AI agent. A general introduction can be obtained from [Chapter 13](https://www.cs.swarthmore.edu/~meeden/cs63/f11/ml-ch13.pdf) of Machine Learning, Tom Mitchell. The implementation is based on a pseudo code given by Meeden [CS63 Lab 6](https://www.cs.swarthmore.edu/~meeden/cs63/f11/lab6.php). 
After training the agent for 200,000 self-play games (~1 min), it reaches an optimal policy. The agent learns to choose the center move if vacant leading to either a win or draw game, as seen in [Reinforcement Learning in Tic-Tac-Toe Game and Its Similar Variations](https://www.cs.dartmouth.edu/~lorenzo/teaching/cs134/Archive/Spring2009/final/PengTao/final_report.pdf). When tested against a random player (randomly chooses valid moves) for 1000 games, AI agent either wins (~99%) or draws (~1%) the game but never loses.

## Software design

1. UML diagram:

<p align="center">
<img src="/UML/Sprint-3/Class dependency chart - Tic-Tac-Toe.png">
</p>

2. Activity diagram:

<p align="center">
<img src="/UML/Sprint-3/Activity diagram - Tic_Tac_Toe.png">
</p>

## Link for SIP document

[SIP Enactment Sheet](https://docs.google.com/spreadsheets/d/1osaNjtBZ5rFgGtWi5gnai63RkGZE8U25gTj9zXKbLFg/edit#gid=0)

## Dependencies

The game has dependency on following packages:
1. [cmake](https://cmake.org/)
2. [googletest](https://github.com/google/googletest)

## Standard install via command-line
```
git clone --recursive https://github.com/ajeetwankhede/Tic-Tac-Toe.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.
Below is a screenshot of code coverage report:
<p align="center">
<img src="/images/codecoverage.png">
</p>

## How to generate Doxygen report

```
sudo apt-get install doxygen
cd <path to repository>
mkdir Doxygen
cd Doxygen
doxygen -g <config_file_name>
gedit <config_file_name>
```
Update PROJECT_NAME, PROJECT_BRIEF, and INPUT fields in the configuration file.
Then run the following command to generate the documentations.
```
doxygen <config_file_name>
```
In doxygen folder, config file (tictactoe) and genertaed reports are saved as html and latex format.

## Tools for static code analysis

Cpplint is used for static code analysis to identify potential source code issues that conflict with the Google C++ style guide. Further, cppcheck is used to detect various kinds of bugs in the code. The results generated by these tools are kept in results directory.
