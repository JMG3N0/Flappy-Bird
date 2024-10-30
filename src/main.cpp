#include "raylib.h"
#include "player.h"


int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	InitWindow(screenWidth, screenHeight, "Flappy Birds");

    player::Player player;
    float speed = 50;
    float x = screenWidth / 4;
    float y = screenHeight / 2;
    float width = 20;

    player::inItPlayer(player, { x , y }, width, width, speed);


    while (!WindowShouldClose())    
    {
        
        player::movePlayer(player);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        player::drawPlayer(player);

        EndDrawing();
        
    }

	return 0;
}