set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    Board_test.cpp
    HumanPlayer_test.cpp
    Player_test.cpp
    RandomPlayer_test.cpp
    TicTacToe_test.cpp
    AIPlayer_test.cpp
    QLearning_test.cpp
    
    ../app/Board.cpp
    ../app/HumanPlayer.cpp
    ../app/Player.cpp
    ../app/RandomPlayer.cpp
    ../app/TicTacToe.cpp
    ../app/AIPlayer.cpp
    ../app/QLearning.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include ../vendor/googletest/googlemock/include
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest gmock)
