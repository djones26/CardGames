cmake_minimum_required(VERSION 3.14)
project(CardGames)

set(CMAKE_CXX_STANDARD 14)

add_executable(CardGames main.cpp Card.cpp Card.h Deck.cpp Deck.h Pile.cpp Pile.h)