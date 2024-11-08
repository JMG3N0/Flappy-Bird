#include "obstacle.h"


void Obstacle::inItObstacle(Obstacle& obstacle, Vector2 pos, float width, float height)
{
	obstacle.hitBox.x = pos.x;
	obstacle.hitBox.y = pos.y;
	obstacle.hitBox.width = width;
	obstacle.hitBox.height = height;
	obstacle.speed = 100;
}

void Obstacle::drawObstacle(Obstacle obstacle)
{
	DrawRectangle(obstacle.hitBox.x, obstacle.hitBox.y, obstacle.hitBox.width, obstacle.hitBox.height, RED);
}

void Obstacle::moveObstacle(Obstacle& obstacle)
{
	obstacle.hitBox.x -= obstacle.speed * GetFrameTime();
}