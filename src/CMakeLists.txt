file(GLOB_RECURSE SOURCES
    "*.cpp"
)

add_library(
    exercises
    ${SOURCES}
)