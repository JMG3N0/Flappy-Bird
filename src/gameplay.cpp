#include "gameplay.h"

#include "raylib.h"
#include "player.h"
#include "obstacle.h"

namespace Gameplay
{
static Player::Player player;
static Obstacle::Obstacle obstacle;

static float obstacleX = 700;
static float obstacleY = GetScreenHeight() / 2;

void Gameplay::inIt()
{
	float speed = 50;
	float x = GetScreenWidth() / 4;
	float y = GetScreenHeight() / 2;
	float width = 20;

	float obstacleWidth = 20;
	float obstacleHeight = 150;

	Player::inItPlayer(player, { x , y }, width, width, speed);
	Obstacle::inItObstacle(obstacle, { obstacleX, obstacleY }, obstacleWidth, obstacleHeight);
}

void Gameplay::checkInput()
{
	Player::movePlayer(player);
}

void Gameplay::update()
{
    Obstacle::moveObstacle(obstacle);

    if (CheckCollisionRecs(player.hitBox, obstacle.hitBox))
    {
        Player::restartPlayer(player);
        obstacle.hitBox.x = obstacleX;
        obstacle.hitBox.y = obstacleY;
    }
    if (player.hitBox.y + player.hitBox.height >= GetScreenHeight())
    {
        Player::restartPlayer(player);
        obstacle.hitBox.x = obstacleX;
        obstacle.hitBox.y = GetRandomValue(0, GetScreenHeight() - obstacle.hitBox.y);
    }

    if (obstacle.hitBox.x <= 0)
    {
        obstacle.hitBox.x = obstacleX;
        obstacle.hitBox.y = GetRandomValue(0, GetScreenHeight() - obstacle.hitBox.y);
    }
}
void Gameplay::draw()
{
    Player::drawPlayer(player);
    Obstacle::drawObstacle(obstacle);

    DrawText("0.1", GetScreenWidth() - MeasureText("0.1", 20) * 2, GetScreenHeight() - MeasureText("0.1", 20), 20, BLACK);
}
}