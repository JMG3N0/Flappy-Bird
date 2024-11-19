#pragma once
#include "raylib.h"

namespace Obstacle
{
	struct Obstacle
	{
		Rectangle freeSpace;
		Rectangle collisionSpace;
		Vector2 initPos;
		float speed;
		float initSpeed;
	};

	void inItObstacle(Obstacle& obstacle);

	void drawObstacle(Obstacle obstacle);

	void moveObstacle(Obstacle& obstacle);

	void restartObstacle(Obstacle& obstacle);
}