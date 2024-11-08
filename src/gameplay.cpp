#include "gameplay.h"

#include "raylib.h"
#include "player.h"
#include "obstacle.h"

namespace Gameplay
{
static Player::Player player;
static Obstacle::Obstacle obstacle;



void Gameplay::inIt()
{

	

	Player::inItPlayer(player);
	Obstacle::inItObstacle(obstacle);
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
        Obstacle::restartObstacle(obstacle);
    }
    if (player.hitBox.y + player.hitBox.height >= GetScreenHeight())
    {
        Player::restartPlayer(player);
        Obstacle::restartObstacle(obstacle);
    }

    if (obstacle.hitBox.x <= 0)
    {
        Obstacle::restartObstacle(obstacle);
    }
}
void Gameplay::draw()
{
    Player::drawPlayer(player);
    Obstacle::drawObstacle(obstacle);

    DrawText("0.1", GetScreenWidth() - MeasureText("0.1", 20) * 2, GetScreenHeight() - MeasureText("0.1", 20), 20, BLACK);
}
}