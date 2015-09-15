# Enable testing, requiring and including gtest
enable_testing()
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(TEST_SOURCES
  ./engine/memory/counting_allocator_test.cpp
)

# Construct testing executable
add_executable (TestGame
  ${SOURCE}
  ${TEST_SOURCES}
)

# Add includes
target_include_directories(TestGame PUBLIC ${INCLUDES})

# Add gtest requirements
target_include_directories(TestGame PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(TestGame ${GTEST_BOTH_LIBRARIES})
target_link_libraries(TestGame ${CMAKE_THREAD_LIBS_INIT})

# Add tests
add_test(TestCountingAllocator
  TestGame --gtest_filter=CountingAllocatorTest*)
