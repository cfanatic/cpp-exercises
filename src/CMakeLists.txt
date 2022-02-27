set(BINARY ${CMAKE_PROJECT_NAME})

add_library(
    exercises
    reverse_string.cpp
    reverse_string.hpp
)

add_executable(${BINARY} main.cpp)
target_link_libraries(${BINARY} exercises)