cmake_minimum_required (VERSION 3.10.3)

set (CMAKE_CXX_FLAGS "-std=c++17 -g -O3 -Wall -Wextra")

include_directories (include)

set (SOURCES
  src/Cli.cxx
  src/main.cxx
  src/Player.cxx
  src/Room.cxx
  src/World.cxx
)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

add_executable (thekinggame.exe ${SOURCES})
