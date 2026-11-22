
cmake_minimum_required(VERSION 3.28)
project(ClubHub LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(clubhub_core
    src/Student.cpp
    src/ConsoleOutput.cpp
)

target_include_directories(clubhub_core PUBLIC include)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(clubhub_tests
    tests/StudentPrivacyTest.cpp
    tests/ConsoleOutputTest.cpp
)

target_link_libraries(clubhub_tests PRIVATE clubhub_core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(clubhub_tests)
