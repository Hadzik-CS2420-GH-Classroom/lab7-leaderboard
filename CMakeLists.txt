cmake_minimum_required(VERSION 3.24)
project(lab7-leaderboard LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -----------------------------------------------------------------------------
# Main executable
# -----------------------------------------------------------------------------
add_executable(${PROJECT_NAME}
    src/BinarySearchTree.cpp
    src/main.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE include)

# -----------------------------------------------------------------------------
# Google Test — fetched at configure time
# -----------------------------------------------------------------------------
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows: prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# -----------------------------------------------------------------------------
# Test executable
# -----------------------------------------------------------------------------
add_executable(run_tests
    src/BinarySearchTree.cpp
    tests/lab7_test.cpp
)
target_include_directories(run_tests PRIVATE include)
target_link_libraries(run_tests GTest::gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(run_tests)
