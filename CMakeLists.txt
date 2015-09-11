cmake_minimum_required (VERSION 2.8)
project (Game)

# Version Number
set (GAME_VERSION_MAJOR 0)
set (GAME_VERSION_MINOR 1)

# Enable testing
enable_testing()

# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)

# Add source files
set (SOURCE
  ${SOURCE}
  game.m.cpp
)

# Construct normal executable
add_executable (Game ${SOURCE})
