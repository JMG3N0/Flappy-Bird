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
    if (true)
    {

    }
}

bool CheckCollision(Rectangle player, Rectangle freeSpace, Rectangle collisionSpace)
{
    Rectangle collisionTop = {collisionSpace.x, collisionSpace.y, collisionSpace.width, freeSpace.y};
    Rectangle collisionLow = {collisionSpace.x, (freeSpace.y+freeSpace.height), collisionSpace.width, collisionSpace.height};

    if (CheckCollisionRecs(player, collisionTop))
    {
        return true;
    }

    if (CheckCollisionRecs(player, collisionLow))
    {
        return true;
    }

    return false;
}

void Gameplay::update()
{
    Obstacle::moveObstacle(obstacle);

    if (CheckCollision(player.hitBox, obstacle.freeSpace, obstacle.collisionSpace) || player.hitBox.y + player.hitBox.height >= static_cast<float>(GetScreenHeight()))
    {
        Player::restartPlayer(player);
        Obstacle::restartObstacle(obstacle);
    }
    

    if (obstacle.freeSpace.x <= 0)
    {
        Obstacle::restartObstacle(obstacle);
    }
}
void Gameplay::draw()
{
    
    Obstacle::drawObstacle(obstacle);
    Player::drawPlayer(player);

   
}

void unloadPlayer()
{
    Player::unload(player);
}
}