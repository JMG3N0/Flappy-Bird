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
    int score;
    int hiScore;
    bool hasHiScore;
    bool gameOver;
};

void inItPlayer(Player& player);

void drawPlayer(Player player, Color colors);

void movePlayer(Player& player);

void restartPlayer(Player& player);

void unload(Player& player);



void showScore(Player player);
}