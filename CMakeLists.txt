cmake_minimum_required(VERSION 3.14)
project(CRTP)
include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY "https://github.com/google/googletest"
        GIT_TAG "05CC6081FCBD0071053DE78238E136B3"
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)

    FetchContent_Populate(googletest)
    message("--- ${googletest_SOURCE_DIR}")
    message("--- ${googletest_BINARY_DIR}")
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

add_executable(Main source/main.cpp source/main.cpp)

add_executable(simple source/simpleExample.cpp)

target_include_directories(simple
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(addfun source/AddFunctionality.cpp )

target_include_directories(simple
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include)

add_subdirectory(test)
