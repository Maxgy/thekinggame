cmake_minimum_required (VERSION 3.11.1)

project (thekinggame)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GCC")
  set (CMAKE_CXX_FLAGS "-std=c++17 -g -O3 -Wall -Wextra")
  include_directories(
    include
    /usr/include
    /usr/include/c++/${CMAKE_CXX_COMPILER_VERSION}
  )
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
  set (CMAKE_CXX_FLAGS "-std=c++17 -g -O3 -Wall -Wextra")
  include_directories(
    include
    /usr/include
    /usr/lib/clang/${CMAKE_CXX_COMPILER_VERSION}/include
  )
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")

endif()

set (SOURCES
  src/Cli.cxx
  src/main.cxx
  src/Player.cxx
  src/Room.cxx
  src/World.cxx
)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ..)

add_executable (thekinggame.exe ${SOURCES})
