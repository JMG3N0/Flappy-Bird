#include "obstacle.h"


void Obstacle::inItObstacle(Obstacle& obstacle)
{
	obstacle.hitBox.x = 700.0f;
	obstacle.hitBox.y = static_cast<float>(GetScreenHeight() / 2);
	obstacle.initPos = {obstacle.hitBox.x, obstacle.hitBox.y};
	obstacle.hitBox.width = 20.0f;
	obstacle.hitBox.height = 150.0f;
	obstacle.speed = 100.0f;
}

void Obstacle::drawObstacle(Obstacle obstacle)
{
	DrawRectangle(obstacle.hitBox.x, obstacle.hitBox.y, obstacle.hitBox.width, obstacle.hitBox.height, RED);
}

void Obstacle::moveObstacle(Obstacle& obstacle)
{
	obstacle.hitBox.x -= obstacle.speed * GetFrameTime();
}

void Obstacle::restartObstacle(Obstacle& obstacle)
{
	obstacle.hitBox = { obstacle.initPos.x, obstacle.initPos.y };
}