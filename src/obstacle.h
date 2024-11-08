#pragma once
#include "raylib.h"

namespace Obstacle
{
	struct Obstacle
	{
		Rectangle hitBox;
		float speed;
	};

	void inItObstacle(Obstacle& obstacle, Vector2 pos, float width, float height);

	void drawObstacle(Obstacle obstacle);

	void moveObstacle(Obstacle& obstacle);

}