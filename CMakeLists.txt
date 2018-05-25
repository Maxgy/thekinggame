cmake_minimum_required (VERSION 3.11.2)

project (thekinggame)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

set (CMAKE_CXX_STANDARD 17)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GCC" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
  set (CMAKE_CXX_FLAGS "-g -O3 -Wall -Wextra")
endif ()

set (SOURCES
  src/Objs/IronSword.cxx
  src/Cli.cxx
  src/main.cxx
  src/Obj.cxx
  src/Path.cxx
  src/Player.cxx
  src/Room.cxx
  src/World.cxx
)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

add_executable (thekinggame.exe ${SOURCES})
