
#include "raylib.h"

int main(void)
{
    // Window dimensions
    int screenWidth = 800;
    int screenHeight = 600;

    // Snake position
    int snakeX = 400;
    int snakeY = 250;

    // Size of each snake segment
    int snakeSize = 20;

    // Create the game window
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        BeginDrawing();

        // Draw the background
        ClearBackground(DARKGRAY);

        // Draw the snake
        DrawRectangle(snakeX, snakeY, snakeSize, snakeSize, GREEN);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
