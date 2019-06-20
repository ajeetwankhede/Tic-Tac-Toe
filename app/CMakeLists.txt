add_executable(shell-app main.cpp Board.cpp HumanPlayer.cpp Player.cpp RandomPlayer.cpp TicTacToe.cpp AIPlayer.cpp QLearning.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
