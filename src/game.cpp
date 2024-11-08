#include "game.h"

#include "raylib.h"

#include "gameplay.h"

namespace Game
{
static const int screenWidth = 800;
static const int screenHeight = 600;

static void inIt()
{
    InitWindow(screenWidth, screenHeight, "Flappy Birds");
    Gameplay::inIt();
}

static void checkInput()
{

    Gameplay::checkInput();

}

static void update()
{
    Gameplay::update();
}

static void draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    Gameplay::draw();

    EndDrawing();

}

void runGame()
{
    inIt();

    while (!WindowShouldClose())
    {
        checkInput();
        update();
        draw();
    }
}
}