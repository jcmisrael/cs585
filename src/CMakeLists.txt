# Include headers in this directory
include_directories(.)
include_directories(engine/memory)

# Add engine/memory source files
set(SOURCE
  ${SOURCE}
  ${CMAKE_CURRENT_SOURCE_DIR}/engine/memory/default_allocator.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/engine/memory/counting_allocator.cpp
)
