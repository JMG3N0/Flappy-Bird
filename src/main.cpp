#include "raylib.h"
#include "player.h"
#include "obstacle.h"

const int screenWidth = 800;
const int screenHeight = 450;

int main()
{
	InitWindow(screenWidth, screenHeight, "Flappy Birds");

    player::Player player;
    float speed = 50;
    float x = screenWidth / 4;
    float y = screenHeight / 2;
    float width = 20;

    obstacle::Obstacle obstacle;

    float obstacleX = screenWidth;
    float obstacleY = screenHeight / 2;
    float obstacleWidth = 20;
    float obstacleHeight = 150;

    player::inItPlayer(player, { x , y }, width, width, speed);
    obstacle::inItObstacle(obstacle, {obstacleX, obstacleY}, obstacleWidth, obstacleHeight);

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
        if (player.hitBox.y + player.hitBox.height >= screenHeight)
        {
            player::restartPlayer(player);
            obstacle.hitBox.x = obstacleX;
            obstacle.hitBox.y = GetRandomValue(0, screenHeight - obstacle.hitBox.y);
        }

        if (obstacle.hitBox.x <= 0)
        {
            obstacle.hitBox.x = obstacleX;
            obstacle.hitBox.y = GetRandomValue(0, screenHeight - obstacle.hitBox.y);
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        player::drawPlayer(player);
        obstacle::drawObstacle(obstacle);

        DrawText("0.1", screenWidth - MeasureText("0.1", 20) * 2, screenHeight - MeasureText("0.1", 20), 20, BLACK);

        EndDrawing();
        
    }

	return 0;
}