cmake_minimum_required(VERSION 3.6)
project(Pandemic6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Role.cpp Role.h Reference.cpp Driver.cpp Player.cpp Player.h cmake-build-debug/Driver.h Reference.h PlayerCards.cpp PlayerCards.h Pawn.cpp Pawn.h)
add_executable(Pandemic6 ${SOURCE_FILES})