# TicTacToe
[![Build Status](https://travis-ci.com/ajeetwankhede/Tic-Tac-Toe.svg?token=PaB15bgFhTxvmjf14qhk&branch=master)](https://travis-ci.com/ajeetwankhede/Tic-Tac-Toe)

---

## Project Overview

The task is to build a Tic Tac Toe game using object oriented programming concepts.

## Breif about Tic Tac Toe ([wikipedia](https://en.wikipedia.org/wiki/Tic-tac-toe))

Tic-tac-toe (American English), noughts and crosses (British English), or Xs and Os is a paper-and-pencil game for two players, X and O, who take turns marking the spaces in a 3×3 grid. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game.

<p align="center">
<img src="/images/Tic-tac-toe.png">
</p>

## Software design

1. UML diagram:

<p align="center">
<img src="/UML/Initial/Class dependency chart - Tic-Tac-Toe.png">
</p>

2. Activity diagram:

<p align="center">
<img src="/UML/Initial/Activity diagram - Tic-Tac-Toe.png">
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

## How to generate Doxygen report

```
sudo apt-get install doxygen
cd <path to repository>
mkdir Doxygen
cd Doxygen
doxygen -g <config_file_name>
gedit <config_file_name>
```
Update PROJECT_NAME and INPUT fields in the configuration file.
Then run the following command to generate the documentations.
```
doxygen <config_file_name>
```
In Doxygen folder, config file and genertaed reports are saved as html and latex format in Doxygen directory.

## Tools for static code analysis

Cpplint is used for static code analysis to identify potential source code issues that conflict with the Google C++ style guide. Further, cppcheck is used to detect various kinds of bugs in the code. The results generated by these tools are kept in results directory.
