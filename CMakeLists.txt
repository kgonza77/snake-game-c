cmake_minimum_required(VERSION 3.20)

project(SnakeGame C)

enable_testing()

include(FetchContent)

FetchContent_Declare(
    unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG v2.7.0
)

FetchContent_MakeAvailable(unity)

add_executable(snake
    main.c
    snake.c
)

target_link_libraries(snake PRIVATE raylib)

add_executable(snake_tests
    tests/test_snake.c
    snake.c
)

target_include_directories(snake_tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(snake_tests PRIVATE unity)

add_test(
    NAME snake_unit_tests
    COMMAND snake_tests
)