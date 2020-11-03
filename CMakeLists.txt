cmake_minimum_required(VERSION 3.14)
project(cpp_template)
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



add_executable(${PROJECT_NAME} source/main.cpp source/main.cpp)


add_subdirectory(test)
