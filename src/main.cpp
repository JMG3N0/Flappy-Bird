#include "raylib.h"


int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Flappy Birds");

    while (!WindowShouldClose())    
    {
        
        BeginDrawing();

        ClearBackground(RAYWHITE);

        

        EndDrawing();
        
    }

	return 0;
}