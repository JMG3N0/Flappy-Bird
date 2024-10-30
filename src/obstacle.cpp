#include "obstacle.h"


void obstacle::inItObstacle(Obstacle& obstacle, Vector2 pos, float width, float height)
{
	obstacle.hitBox.x = pos.x;
	obstacle.hitBox.y = pos.y;
	obstacle.hitBox.width = width;
	obstacle.hitBox.height = height;
	obstacle.speed = 100;
}

void obstacle::drawObstacle(Obstacle obstacle)
{
	DrawRectangle(obstacle.hitBox.x, obstacle.hitBox.y, obstacle.hitBox.width, obstacle.hitBox.height, RED);
}

void obstacle::moveObstacle(Obstacle& obstacle)
{
	obstacle.hitBox.x -= obstacle.speed * GetFrameTime();
}