#include "obstacle.h"


void Obstacle::inItObstacle(Obstacle& obstacle)
{
	
	obstacle.freeSpace.x = 700.0f;
	obstacle.freeSpace.y = static_cast<float>(GetScreenHeight() / 2);
	obstacle.collisionSpace.x = obstacle.freeSpace.x;
	obstacle.collisionSpace.y = 0;
	obstacle.initPos = {obstacle.freeSpace.x, obstacle.freeSpace.y};
	obstacle.freeSpace.width = 20.0f;
	obstacle.freeSpace.height = 150.0f;
	obstacle.collisionSpace.width = 20.0f;
	obstacle.collisionSpace.height = (static_cast<float>(GetScreenHeight()) - obstacle.collisionSpace.y);
	obstacle.speed = 100.0f;
}

void Obstacle::drawObstacle(Obstacle obstacle)
{

	DrawRectangle(static_cast<int>(obstacle.collisionSpace.x), static_cast<int>(obstacle.collisionSpace.y), static_cast<int>(obstacle.collisionSpace.width), static_cast<int>(obstacle.collisionSpace.height), GREEN);
	
	

#if _DEBUG
		DrawRectangle(static_cast<int>(obstacle.collisionSpace.x), static_cast<int>(obstacle.collisionSpace.y), static_cast<int>(obstacle.collisionSpace.width), static_cast<int>(obstacle.collisionSpace.height), RED);
#endif // _DEBUG

		DrawRectangle(static_cast<int>(obstacle.freeSpace.x), static_cast<int>(obstacle.freeSpace.y), static_cast<int>(obstacle.freeSpace.width), static_cast<int>(obstacle.freeSpace.height), WHITE);
}

void Obstacle::moveObstacle(Obstacle& obstacle)
{
	obstacle.freeSpace.x -= obstacle.speed * GetFrameTime();
	obstacle.collisionSpace.x -= obstacle.speed * GetFrameTime();
}

void Obstacle::restartObstacle(Obstacle& obstacle)
{
	obstacle.freeSpace.x = obstacle.initPos.x;
	obstacle.collisionSpace.x = obstacle.initPos.x;
	obstacle.freeSpace.y = obstacle.initPos.y;
}