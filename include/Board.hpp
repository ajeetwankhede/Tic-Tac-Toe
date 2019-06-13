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
 *  @file    Board.hpp
 *  @author  Ajeet Wankhede
 *  @date    06/11/2019
 *  @version 1.0
 *
 *  @brief Coding challenge by Plus One Robotics
 *
 *  @section DESCRIPTION
 *  This is a Board class header file.
 *  This class is used to operate upon the board for Tic Tac Toe game.
 *  The current state of the board should be updated every iteration.
 *  Utility functions such as draw, clear, update, and check win are provided.
 */

#ifndef INCLUDE_BOARD_HPP_
#define INCLUDE_BOARD_HPP_

class Board {
  char board[9];
  char marker;

 public:
  /**
   *   @brief Default constructor for Board.
   *
   *   @param nothing
   *   @return nothing
   */
  Board();
  /**
   *   @brief Default destructor for Board.
   *
   *   @param nothing
   *   @return nothing
   */
  virtual ~Board();
  /**
   *   @brief Displays the current board on the screen.
   *
   *   @param nothing
   *   @return nothing
   */
  void drawBoard();
  /**
   *   @brief Clears all the contents of board and fill it with blanks.
   *
   *   @param nothing
   *   @return nothing
   */
  void clearBoard();
  /**
   *   @brief Fills the position on the board with the marker.
   *
   *   @param int value stating the position to fill.
   *   @return nothing
   */
  void updateBoard(int pos);
  /**
   *   @brief Toggles the value in the marker between 'X' & 'O'.
   *
   *   @param nothing
   *   @return nothing
   */
  void toggleMarker();
  /**
   *   @brief Checks all the conditions of winning the game.
   *
   *   @param nothing
   *   @return bool value true if player wins, else returns false.
   */
  bool isWin();
  /**
   *   @brief Set the state of the board
   *
   *   @param char array of new board
   *   @return nothing
   */
  void setBoard(const char b[9]);
  /**
   *   @brief Get the state of the board
   *
   *   @param int value of pos on the board
   *   @return char value at pos on the board
   */
  char getBoard(const int pos);
  /**
   *   @brief Set the marker
   *
   *   @param char value to be set
   *   @return nothing
   */
  void setMarker(const char c);
  /**
   *   @brief Get the marker
   *
   *   @param nothing
   *   @return char value of marker
   */
  char getMarker();
};

#endif  // INCLUDE_BOARD_HPP_
