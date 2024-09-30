cmake_minimum_required(VERSION 3.20)

add_subdirectory(./lib/googletest-main-2)
set(gtest_SOURCE_DIR ./lib/googletest-main-2)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES ActivityTest.cpp runAllTests.cpp
        TimeTest.cpp
        DateTest.cpp
)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core)