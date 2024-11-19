#include "game.h"

#include "raylib.h"

#include "gameplay.h"



namespace Game
{
static const int screenWidth = 800;
static const int screenHeight = 600;
static int HiScore = 0;
static bool pausedGame = false;

Menu menu;







void titleMenu(Menu& menu)
  {
    int ScreenWidth = GetScreenWidth();
    int ScreenHeight = GetScreenHeight();

    ClearBackground(RAYWHITE);

    DrawText("Neo Migration", (ScreenWidth / 2) - 75, (ScreenHeight / 2), 20, BLUE);
    DrawText("Press any key to continue...", (ScreenWidth / 2) - 130, ((ScreenHeight / 2) + 30), 20, BLUE);
    

    if (GetKeyPressed() >= 32 && GetKeyPressed() <= 168 || IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) || IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
    {

        menu = Main;
    }

    DrawText("0.3", GetScreenWidth() - MeasureText("0.1", 20) * 2,  MeasureText("0.2", 20), 20, BLACK);
  }

void creditsMenu(Menu& menu)
{
    int ScreenWidth = GetScreenWidth();
    int ScreenHeight = GetScreenHeight(); 
    Vector2 mousePos = GetMousePosition();

    ClearBackground(RAYWHITE);

    DrawText("Game and Sprites made by Joan Manuel Rivas Cepeda", (ScreenWidth / 6), (ScreenHeight / 2), 20, BLUE);
    DrawText("Go Back", (30), (ScreenHeight -20), 20, BLUE);
    DrawText("Play Game", (ScreenWidth - 120), (ScreenHeight - 20), 20, BLUE);
    if (mousePos.y <= screenHeight && mousePos.y >= ScreenHeight - 40)
    {
        if (mousePos.x <= (ScreenWidth / 6) )
        {
            DrawText("Go Back", (30), (ScreenHeight - 20), 20, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                
                menu = Main;
            }
        }
        if (mousePos.x >= ScreenWidth - 140)
        {
            DrawText("Play Game", (ScreenWidth - 120), (ScreenHeight - 20), 20, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Gameplay::inIt();
                menu = Game;
            }
        }
    }
    DrawText("0.3", GetScreenWidth() - MeasureText("0.1", 20) * 2, MeasureText("0.2", 20), 20, BLACK);
}

 void mainMenu(Menu& menu)
 {
    Vector2 mousePos = GetMousePosition();
    int ScreenWidth = GetScreenWidth();
    int ScreenHeight = GetScreenHeight();

    ClearBackground(RAYWHITE);

    DrawText("Neo Migration", (ScreenWidth / 2)-75, (ScreenHeight / 2), 20, BLUE);
    DrawText("Play", (ScreenWidth / 2)-20, ((ScreenHeight / 2) + 40), 20, BLUE);
    DrawText("Credits", (ScreenWidth / 2)-20, ((ScreenHeight / 2) + 60), 20, BLUE);
    DrawText("Exit", (ScreenWidth / 2)-20, ((ScreenHeight / 2) + 80), 20, BLUE);

    if (mousePos.x <= ((ScreenWidth / 2) +40) && mousePos.x >= ((ScreenWidth / 2) - 40))
    {
        if (mousePos.y <= ((screenHeight/2)+40)+9 && mousePos.y >= ((screenHeight / 2)+40) - 9)
        {
            DrawText("Play", (ScreenWidth / 2) - 20, ((ScreenHeight / 2) + 40), 20, RED);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Gameplay::inIt();
                menu = Game;
            }
        }
        
        if (mousePos.y <= ((screenHeight / 2) + 60) + 9 && mousePos.y >= ((screenHeight / 2) + 60) - 9)
        {
            DrawText("Credits", (ScreenWidth / 2) - 20, ((ScreenHeight / 2) + 60), 20, RED);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                menu = Credits;
            }
        }
       
        if (mousePos.y <= ((screenHeight / 2) + 80) + 9 && mousePos.y >= ((screenHeight / 2) + 80) - 9)
        {
            DrawText("Exit", (ScreenWidth / 2) - 20, ((ScreenHeight / 2) + 80), 20, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                CloseWindow();
            }
        }
        
        
    }

#if _DEBUG
    if (IsKeyPressed(KEY_A))
    {
        menu = Title;
    }
#endif // _DEBUG

    
    
    DrawText("0.3", GetScreenWidth() - MeasureText("0.1", 20) * 2,  MeasureText("0.2", 20) , 20, BLACK);
    
 }

 void drawPause(bool& ispaused)
 {
     int screenHeight = GetScreenHeight();
     int screenWidth = GetScreenWidth();
     Vector2 mousePos = GetMousePosition();

     if (ispaused == true)
     {
         DrawRectangle((screenWidth / 4), (screenHeight / 4), 400, 300, BLACK);
         DrawText("PAUSED", (screenWidth / 2) - 120, (screenHeight / 4) + 20, 60, WHITE);
         DrawText("Resume", (screenWidth / 2) - 40, (screenHeight / 2) , 20, WHITE);
         DrawText("Return to Main Menu", (screenWidth / 2) - 110, (screenHeight / 2) + 40, 20, WHITE);
         DrawText("Exit Game", (screenWidth / 2) - 50, (screenHeight / 2) + 80, 20, WHITE);
         if (mousePos.x <= screenWidth / 2+ 120 && mousePos.x >= screenWidth / 2 - 120)
         {
             if (mousePos.y >= ((screenHeight/2) -20) && mousePos.y <= ((screenHeight/2)+20))
             {
                 DrawText("Resume", (screenWidth / 2) - 40, (screenHeight / 2), 20, RED);
                 if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                 {
                     ispaused = false;
                 }
             }
             if (mousePos.y >= ((screenHeight / 2) + 40) - 20 && mousePos.y <= ((screenHeight / 2) + 40) + 20)
             {
                 DrawText("Return to Main Menu", (screenWidth / 2) - 110, (screenHeight / 2) + 40, 20, RED);
                 if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                 {
                     menu = Main;
                     ispaused = false;
                 }
             }
             if (mousePos.y >= ((screenHeight / 2) + 80) -20 && mousePos.y <= ((screenHeight / 2) + 80) + 20)
             {
                 DrawText("Exit Game", (screenWidth / 2) - 50, (screenHeight / 2) + 80, 20, RED);
                 if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                 {
                     
                     CloseWindow();
                 }
             }
             
             
         }
         
         
     }
 }

 void drawNupdate()
{

   


    BeginDrawing();

    ClearBackground(RAYWHITE);

    switch (menu)
    {
    case Game::Title:
        titleMenu(menu);
        break;
    case Game::Main:
        mainMenu(menu);
        break;
    case Game::Credits:
        creditsMenu(menu);
        break;
    case Game::Game:
        
        Gameplay::draw();
        if (Gameplay::isGameOver() == true)
        {
            if (Gameplay::gameOverScreen() == 1)
            {
                menu = Main;
            }
        }
        else if (Gameplay::isGameOver() == false)
        {


            drawPause(pausedGame);
            if (IsKeyPressed(KEY_ESCAPE))
            {
                pausedGame = true;
            }
            if (pausedGame == false)
            {
                Gameplay::checkInput();
                Gameplay::update();
            }
        }
        break;
    default:
        break;
    }

    EndDrawing();

    

   

}

 void runGame()
{
    menu = Title;
    InitWindow(screenWidth, screenHeight, "Neo Migration");

    SetExitKey(NULL);

    while (!WindowShouldClose())
    {
        drawNupdate();
    }
    

    
    
    Gameplay::unload();
   
    
    
   
    CloseWindow();
}


}