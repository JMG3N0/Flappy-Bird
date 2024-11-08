#pragma once
#include "raylib.h"

namespace Obstacle
{
	struct Obstacle
	{
		Rectangle hitBox;
		Vector2 initPos;
		float speed;
	};

	void inItObstacle(Obstacle& obstacle);

	void drawObstacle(Obstacle obstacle);

	void moveObstacle(Obstacle& obstacle);

	void restartObstacle(Obstacle& obstacle);
}