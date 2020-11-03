add_executable(mainTest mainTest.cpp)

target_link_libraries(mainTest PRIVATE
        PRIVATE
            gtest
            gmock_main
        )

add_test(test1  mainTest COMMAND mainTest)
