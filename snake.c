#include "snake.h"

void MoveSnake(Snake *snake)
{
    snake->x += snake->directionX * snake->size;
    snake->y += snake->directionY * snake->size;
}


void ChangeSnakeDirection(Snake *snake, int newDirectionX, int newDirectionY)
{
    // Prevent the snake from immediately reversing direction
    if (snake->directionX == -newDirectionX &&
        snake->directionY == -newDirectionY)
    {
        return;
    }

    snake->directionX = newDirectionX;
    snake->directionY = newDirectionY;
}