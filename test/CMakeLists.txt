# Enable testing, requiring and including gtest
enable_testing()
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Construct testing executable
add_executable (TestGame
  tautology.cpp
)
target_link_libraries(TestGame ${GTEST_BOTH_LIBRARIES})
target_link_libraries(TestGame ${CMAKE_THREAD_LIBS_INIT})
add_test(RunAllTests TestGame)
