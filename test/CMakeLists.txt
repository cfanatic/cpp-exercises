include(GoogleTest)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(reverse_string_test reverse_string_test.cpp)
target_link_libraries(reverse_string_test exercises gtest_main)

gtest_discover_tests(reverse_string_test)