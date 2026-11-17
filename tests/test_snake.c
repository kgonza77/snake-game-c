#include "unity.h"
#include "snake.h"

void setUp(void)
{
}

void tearDown(void)
{
}

// Snake movement tests
void test_move_snake_right(void)
{
    Snake snake = {
        .x = 100,
        .y = 100,
        .size = 20,
        .directionX = 1,
        .directionY = 0
    };

    MoveSnake(&snake);

    TEST_ASSERT_EQUAL_INT(120, snake.x);
    TEST_ASSERT_EQUAL_INT(100, snake.y);
}

void test_move_snake_left(void)
{
    Snake snake = {
        .x = 100,
        .y = 100,
        .size = 20,
        .directionX = -1,
        .directionY = 0
    };

    MoveSnake(&snake);

    TEST_ASSERT_EQUAL_INT(80, snake.x);
    TEST_ASSERT_EQUAL_INT(100, snake.y);
}

void test_move_snake_up(void)
{
    Snake snake = {
        .x = 100,
        .y = 100,
        .size = 20,
        .directionX = 0,
        .directionY = -1
    };

    MoveSnake(&snake);

    TEST_ASSERT_EQUAL_INT(100, snake.x);
    TEST_ASSERT_EQUAL_INT(80, snake.y);
}

void test_move_snake_down(void)
{
    Snake snake = {
        .x = 100,
        .y = 100,
        .size = 20,
        .directionX = 0,
        .directionY = 1
    };

    MoveSnake(&snake);

    TEST_ASSERT_EQUAL_INT(100, snake.x);
    TEST_ASSERT_EQUAL_INT(120, snake.y);
}

// Snake valid-turn tests
void test_change_direction_right_to_down(void)
{
    Snake snake = {
        .x = 100,
        .y = 100,
        .size = 20,
        .directionX = 1,
        .directionY = 0
    };

    ChangeSnakeDirection(&snake, 0, 1);

    TEST_ASSERT_EQUAL_INT(0, snake.directionX);
    TEST_ASSERT_EQUAL_INT(1, snake.directionY);
}

void test_change_direction_right_to_up(void)
{
    Snake snake = {
        .x = 100,
        .y = 100,
        .size = 20,
        .directionX = 1,
        .directionY = 0
    };

    ChangeSnakeDirection(&snake, 0, -1);

    TEST_ASSERT_EQUAL_INT(0, snake.directionX);
    TEST_ASSERT_EQUAL_INT(-1, snake.directionY);
}

// Revesal test
void test_change_direction_blocks_right_to_left(void)
{
    Snake snake = {
        .x = 100,
        .y = 100,
        .size = 20,
        .directionX = 1,
        .directionY = 0
    };

    ChangeSnakeDirection(&snake, -1, 0);

    TEST_ASSERT_EQUAL_INT(1, snake.directionX);
    TEST_ASSERT_EQUAL_INT(0, snake.directionY);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_move_snake_right);
    RUN_TEST(test_move_snake_left);
    RUN_TEST(test_move_snake_up);
    RUN_TEST(test_move_snake_down);

    RUN_TEST(test_change_direction_right_to_down);
    RUN_TEST(test_change_direction_right_to_up);

    RUN_TEST(test_change_direction_blocks_right_to_left);


    return UNITY_END();
}
