#include "obstacle.h"
#include <iostream>


void Obstacle::inItObstacle(Obstacle& obstacle)
{
	
	obstacle.freeSpace.x = 799.0f;
	obstacle.freeSpace.y = static_cast<float>(GetScreenHeight() / 2);
	obstacle.collisionSpace.x = obstacle.freeSpace.x;
	obstacle.collisionSpace.y = 0;
	obstacle.initPos = {obstacle.freeSpace.x, obstacle.freeSpace.y};
	obstacle.freeSpace.width = 20.0f;
	obstacle.freeSpace.height = 150.0f;
	obstacle.collisionSpace.width = 20.0f;
	obstacle.collisionSpace.height = (static_cast<float>(GetScreenHeight()) - (obstacle.freeSpace.y + obstacle.freeSpace.height));
	obstacle.speed = 100.0f;
	obstacle.initSpeed = obstacle.speed;
}

void Obstacle::drawObstacle(Obstacle obstacle, Color colorAdd)
{

	int screenHeight = GetScreenHeight();
	//Color color = SKYBLUE;
	/*color.b -= colorAdd.b;
	color.r -= colorAdd.r;
	color.g -= colorAdd.g;*/

	DrawRectangle(static_cast<int>(obstacle.collisionSpace.x), static_cast<int>(obstacle.collisionSpace.y), static_cast<int>(obstacle.collisionSpace.width), static_cast<int>(obstacle.freeSpace.y), SKYBLUE);
	DrawRectangle(static_cast<int>(obstacle.collisionSpace.x), static_cast<int>(obstacle.freeSpace.y) + static_cast<int>(obstacle.freeSpace.height), static_cast<int>(obstacle.collisionSpace.width), static_cast<int>( screenHeight - (obstacle.freeSpace.height+obstacle.freeSpace.y)), SKYBLUE);
	
	

#if _DEBUG
	DrawRectangle(static_cast<int>(obstacle.collisionSpace.x), static_cast<int>(obstacle.collisionSpace.y), static_cast<int>(obstacle.collisionSpace.width), static_cast<int>(obstacle.freeSpace.y), RED);
	DrawRectangle(static_cast<int>(obstacle.collisionSpace.x), static_cast<int>(obstacle.freeSpace.y) + static_cast<int>(obstacle.freeSpace.height), static_cast<int>(obstacle.collisionSpace.width), static_cast<int>(obstacle.collisionSpace.height), RED);
		DrawRectangle(static_cast<int>(obstacle.freeSpace.x), static_cast<int>(obstacle.freeSpace.y), static_cast<int>(obstacle.freeSpace.width), static_cast<int>(obstacle.freeSpace.height), WHITE);
#endif // _DEBUG

		
}

void Obstacle::moveObstacle(Obstacle& obstacle)
{
	obstacle.freeSpace.x -= obstacle.speed * GetFrameTime();
	obstacle.collisionSpace.x -= obstacle.speed * GetFrameTime();
	
}

void Obstacle::restartObstacle(Obstacle& obstacle)
{
	int screenHeight = GetScreenHeight();
	float newPosY = static_cast<float>(rand() % screenHeight - obstacle.freeSpace.height)+ 40.0f;

	obstacle.freeSpace.x = obstacle.initPos.x ;
	obstacle.collisionSpace.x = obstacle.initPos.x;
	obstacle.freeSpace.y = newPosY ;

}