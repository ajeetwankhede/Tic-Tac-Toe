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
 *  @brief
 *  This is a Board class header file.
 *  This class is used to operate upon the board for Tic Tac Toe game.
 *  Utility functions such as draw, clear, toggle, update, and check win are provided.
 *
 */

#ifndef INCLUDE_BOARD_HPP_
#define INCLUDE_BOARD_HPP_

#include <string>

class Board {
  /**
   *   @brief Stores the board state
   */
  std::string board;
  /**
   *   @brief Stores the marker
   */
  char marker;

 public:
  /**
   *   @brief Default constructor for Board.
   */
  Board()
      : board("123456789"),
        marker('X'),
        testing(false) {
  }
  /**
   *   @brief Default destructor for Board.
   */
  virtual ~Board();
  /**
   *   @brief Displays the current board on the screen.
   *   @return String for printing the board
   */
  std::string drawBoard();
  /**
   *   @brief Clears all the contents of board and fills with blanks.
   */
  void clearBoard();
  /**
   *   @brief Fills the position on the board with the marker.
   *   @param pos am integer stating the position to fill.
   */
  virtual void updateBoard(int pos);
  /**
   *   @brief Toggles the value in the marker between 'X' & 'O'.
   */
  virtual void toggleMarker();
  /**
   *   @brief Checks all the conditions of winning the game.
   *   @return True if player wins, else returns false.
   */
  virtual bool isWin();
  /**
   *   @brief Set the entire board with the given string
   *   @param b a string of new board
   */
  void setBoard(std::string b);
  /**
   *   @brief Get the state of the board
   *   @param pos an integer of move on the board
   *   @return Mark at the pos on the board
   */
  char getBoard(const int pos);
  /**
   *   @brief Get the entire board
   *   @return The board
   */
  virtual std::string getEBoard();
  /**
   *   @brief Set the marker
   *   @param c a char value to be set
   */
  void setMarker(const char c);
  /**
   *   @brief Get the marker
   *   @return Marker
   */
  char getMarker();
  /**
   *   @brief true if testing else false
   */
  bool testing;
};

#endif  // INCLUDE_BOARD_HPP_
