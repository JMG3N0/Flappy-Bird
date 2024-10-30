#include "raylib.h"
#include "player.h"
#include "obstacle.h"

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

    obstacle::Obstacle obstacle;

    float obstacleX = screenWidth / 2;
    float obstacleY = screenHeight / 2;
    float obstacleWidth = 20;
    float obstacleHeight = screenHeight - obstacleY;

    player::inItPlayer(player, { x , y }, width, width, speed);
    obstacle::inItObstacle(obstacle, { obstacleX, obstacleY }, obstacleWidth, obstacleHeight);

    while (!WindowShouldClose())    
    {
        
        player::movePlayer(player);
        obstacle::moveObstacle(obstacle);

        if (CheckCollisionRecs(player.hitBox, obstacle.hitBox))
        {
            player.hitBox.x = x;
            player.hitBox.y = y;
            obstacle.hitBox.x = obstacleX;
            obstacle.hitBox.y = obstacleY;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        player::drawPlayer(player);
        obstacle::drawObstacle(obstacle);

        EndDrawing();
        
    }

	return 0;
}