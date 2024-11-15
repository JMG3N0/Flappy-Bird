#pragma once
#include "raylib.h"

namespace Player
{ 
struct Player
{
    Texture2D sprite;
    Rectangle hitBox;
    Vector2 initPos;
    float speed;
    float initSpeed;
    float jumpForce;
    int frameNumber;
};

void inItPlayer(Player& player);

void drawPlayer(Player player);

void movePlayer(Player& player);

void restartPlayer(Player& player);

void unload(Player& player);
}