set(BINARY ${CMAKE_PROJECT_NAME}-test)

include(GoogleTest)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE SOURCES_TEST
    "*.cpp"
)

add_executable(${BINARY} ${SOURCES_TEST})
target_link_libraries(${BINARY} exercises gtest_main)

gtest_discover_tests(${BINARY})