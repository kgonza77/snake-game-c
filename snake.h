#ifndef SNAKE_H
#define SNAKE_H

typedef struct
{
    int x;
    int y;
    int size;
    int directionX;
    int directionY;

} Snake;

void MoveSnake(Snake *snake);
void ChangeSnakeDirection(Snake *snake, int newDirectionX, int newDirectionY);

#endif