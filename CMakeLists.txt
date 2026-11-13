cmake_minimum_required(VERSION 3.20)

project(SnakeGame C)

add_executable(snake
    main.c
    snake.c
)

target_link_libraries(snake PRIVATE raylib)