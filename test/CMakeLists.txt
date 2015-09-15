# Set testing binary name
set(TESTING_BINARY_NAME
  TestGame
)

# Enable testing, requiring and including gtest
enable_testing()
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(TEST_SOURCE_ENGINE_MEMORY
  engine/memory/counting_allocator_test.cpp
)

set(TEST_SOURCE_ENGINE_CONTAINERS
  engine/containers/dynamic_array_test.cpp
)

set(TEST_SOURCES
  ${TEST_SOURCES}
  ${TEST_SOURCE_ENGINE_MEMORY}
  ${TEST_SOURCE_ENGINE_CONTAINERS}
)

# Construct testing executable
add_executable (${TESTING_BINARY_NAME}
  ${SOURCE}
  ${TEST_SOURCES}
)

# Add includes
target_include_directories(${TESTING_BINARY_NAME} PUBLIC ${INCLUDES})

# Add gtest requirements
target_include_directories(${TESTING_BINARY_NAME} PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(${TESTING_BINARY_NAME} ${GTEST_BOTH_LIBRARIES})
target_link_libraries(${TESTING_BINARY_NAME} ${CMAKE_THREAD_LIBS_INIT})

# Add tests
add_test(TestCountingAllocator
  TestGame --gtest_filter=CountingAllocatorTest*)
add_test(TestDynamicArray
  TestGame --gtest_filter=DynamicArrayTest*)
