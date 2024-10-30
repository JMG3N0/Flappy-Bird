#pragma once
#include "raylib.h"

namespace player
{ 
struct Player
{
    Rectangle hitBox;
    float speed;
};

void inItPlayer(Player& player, Vector2 pos, float width, float height, float speed);

void drawPlayer(Player player);

void movePlayer(Player& player);
}