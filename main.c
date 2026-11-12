
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

    //Snake movement direction
    int directionX = 1;
    int directionY = 0;

    // Control how often the snake moves (in seconds)
    float moveTimer = 0.0f;
    float moveInterval = 0.2f; // Move every 0.2 seconds

    // Create the game window
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()){

        //Handle keyboard input to change direction
        if (IsKeyDown(KEY_UP) && directionY != 1) 
        {
            directionY = -1; 
            directionX = 0;
        }

        if (IsKeyDown(KEY_DOWN) && directionY != -1) 
        {
            directionY = 1; 
            directionX = 0;
        }
        
        if (IsKeyDown(KEY_LEFT) && directionX != 1) 
        {
            directionX = -1; 
            directionY = 0;
        }
        
        if (IsKeyDown(KEY_RIGHT) && directionX != -1) 
        {
            directionX = 1; 
            directionY = 0;
        }

        // Add the time since the last frame to the move timer
        moveTimer += GetFrameTime();

        // Move the snake only if the move timer exceeds the move interval
        if (moveTimer >= moveInterval)
        {
            snakeX += directionX * snakeSize;
            snakeY += directionY * snakeSize;

            moveTimer = 0.0f;
        }

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
