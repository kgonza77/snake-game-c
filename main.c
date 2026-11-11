#include <stdio.h>
#include "raylib.h"

int main(void)
{
    // Creates a 800px by 600px window with the title "Snake Game"
    InitWindow(800, 600, "Snake Game");

    // Set the game to run at 60 frames per second
    SetTargetFPS(60);

    // Keep the game running until the window is closed
    while (!WindowShouldClose())
    {
        BeginDrawing();

        // Fill the window with a dark background
        ClearBackground(DARKGRAY);

        // Draw some text on the screen
        DrawText("Hungry Snake!", 250, 250, 30, GREEN);

        EndDrawing();
    }

    // Close the window when the game ends
    CloseWindow();

    return 0;
}
