#include "game.h"

#include "raylib.h"

#include "gameplay.h"



namespace Game
{
static const int screenWidth = 800;
static const int screenHeight = 600;

Menu menu;

static void inIt()
{
    menu = Title;
    InitWindow(screenWidth, screenHeight, "Flappy Birds");
    
    
}



static void update()
{
    switch (menu)
    {
    case Game::Title:
        break;
    case Game::Main:
        break;
    case Game::Credits:
        break;
    case Game::Game:
        Gameplay::inIt();

        Gameplay::update();
        break;
    default:
        break;
    }

    
}

static void draw()
{
    BeginDrawing();

    ClearBackground(RAYWHITE);

    switch (menu)
    {
    case Game::Title:
        DrawText("Play", (GetScreenWidth() / 2), (GetScreenHeight() / 2), 90, BLUE);
        break;
    case Game::Main:
        break;
    case Game::Credits:
        break;
    case Game::Game:
        Gameplay::draw();
        break;
    default:
        break;
    }

    EndDrawing();

    

}

void runGame()
{
    inIt();

   
    switch (menu)
    {
    case Game::Title:
        draw();
        break;

    case Game::Main:
        break;

    case Game::Credits:
        break;

    case Game::Game:
        Gameplay::inIt();
        while (!WindowShouldClose())
        {
            Gameplay::checkInput();
            Gameplay::update();
            Gameplay::draw();
        }
        Gameplay::unloadPlayer();
        break;
    default:
        break;
    }
    
   
    
    
   
   // CloseWindow();
}


}