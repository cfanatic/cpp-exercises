cmake_minimum_required(VERSION 3.0.0)
project(cpp-exercises VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(BINARY ${CMAKE_PROJECT_NAME}-debug)

enable_testing()

include_directories(include)
add_subdirectory(src)
add_subdirectory(test)

add_executable(${BINARY} main.cpp)
target_link_libraries(${BINARY} exercises)