
#include "raylib.h"
#include "snake.h"

int main(void)
{
    // Window dimensions
    int screenWidth = 800;
    int screenHeight = 600;

    // Create the snake
    Snake snake = {
        400,  // x
        250,  // y
        20,   // size
        1,    // directionX
        0     // directionY
    };

    // Control how often the snake moves (in seconds)
    float moveTimer = 0.0f;
    float moveInterval = 0.2f; // Move every 0.2 seconds

    // Create the game window
    InitWindow(screenWidth, screenHeight, "Snake Game");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()){

        // Handle keyboard input
        if (IsKeyDown(KEY_UP))
        {
            ChangeSnakeDirection(&snake, 0, -1);
        }

        if (IsKeyDown(KEY_DOWN))
        {
            ChangeSnakeDirection(&snake, 0, 1);
        }

        if (IsKeyDown(KEY_LEFT))
        {
            ChangeSnakeDirection(&snake, -1, 0);
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            ChangeSnakeDirection(&snake, 1, 0);
        }

        // Add the time since the last frame to the move timer
        moveTimer += GetFrameTime();

        // Move the snake only if the move timer exceeds the move interval
        if (moveTimer >= moveInterval)
        {
            MoveSnake(&snake);

            moveTimer = 0.0f;
        }

        BeginDrawing();

        // Draw the background
        ClearBackground(DARKGRAY);

        // Draw the snake
        DrawRectangle(
            snake.x,
            snake.y,
            snake.size,
            snake.size,
            GREEN
        );

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
