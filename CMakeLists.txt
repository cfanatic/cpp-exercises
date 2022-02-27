cmake_minimum_required(VERSION 3.0.0)
project(cpp-exercises VERSION 1.0.0)

include(CPack)
include(GoogleTest)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(application main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

enable_testing()

add_executable(reverse_string_test reverse_string_test.cpp)
target_link_libraries(reverse_string_test gtest_main)

gtest_discover_tests(reverse_string_test)