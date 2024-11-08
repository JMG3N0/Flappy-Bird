#pragma once
#include "raylib.h"

namespace Player
{ 
struct Player
{
    Rectangle hitBox;
    Vector2 initPos;
    float speed;
    float initSpeed;
    float jumpForce;
};

void inItPlayer(Player& player);

void drawPlayer(Player player);

void movePlayer(Player& player);

void restartPlayer(Player& player);
}