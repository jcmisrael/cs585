# Include headers
set(INCLUDES
  ${INCLUDES}
  ${CMAKE_CURRENT_SOURCE_DIR}/engine/memory
  ${CMAKE_CURRENT_SOURCE_DIR}/engine/containers
  PARENT_SCOPE
)

#include_directories(.)
#include_directories(./engine/memory)
#include_directories(./engine/containers)


# Add engine/memory source files
set(SOURCE_ENGINE_MEMORY
  ${CMAKE_CURRENT_SOURCE_DIR}/engine/memory/default_allocator.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/engine/memory/counting_allocator.cpp
)

set(SOURCE
  ${SOURCE}
  ${SOURCE_ENGINE_MEMORY}
  PARENT_SCOPE
)
