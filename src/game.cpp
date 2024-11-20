#include "game.h"

#include <iostream>

#include "raylib.h"

#include "gameplay.h"



namespace Game
{
static const int screenWidth = 800;
static const int screenHeight = 600;
static bool multiplayer = false;
static bool pausedGame = false;
static Music titleMusic;
static Music gameMusic;
static Font font;

Menu menu;

void unloadAll()
{
    Gameplay::unload(multiplayer);
    UnloadFont(font);
    UnloadMusicStream(titleMusic);
    UnloadMusicStream(gameMusic);
    
}

void tutorial(bool multiplayer)
{
    int ScreenWidth = GetScreenWidth();
    int ScreenHeight = GetScreenHeight();
    Vector2 mousePos = GetMousePosition();


    if (multiplayer == true)
    {
        DrawTextEx(font, "To play the game you must reach the highest\n\nscore posible while not hitting the icicle.", { 20.f, static_cast<float>(ScreenHeight / 4) - 30 }, 25, 1.0f, BLUE);
        DrawTextEx(font, "While falling, player 1 can try and flap their\n\nwings by pressing 'W'.", { 20.f, static_cast<float>(ScreenHeight / 2) - 90 }, 25, 1.0f, RED);
        DrawTextEx(font, "Player 2 can flap their wings by pressing the \n\n'UP' arrow on the keyboard.", { 20.f, static_cast<float>(ScreenHeight / 2) - 20 }, 25, 1.0f, DARKBLUE);
        DrawTextEx(font, "Each gain 1 point for outpacing the icicle enough \n\nthat it has disappeared from the screen, but \n\ndoing that will make you fly faster.If you need to\n\ntake a break, you can press Escape to pause\n\nthe game.", { 20.f, static_cast<float>(ScreenHeight / 2) + 60 }, 25, 1.0f, BLUE);
    }
    else
    {
        DrawTextEx(font, "To play the game you must reach the highest\n\n score posible while not hitting the icicle. While\n\n you are falling, you can try and flap your wings\n\n by pressing 'W'. You gain 1 point each\n\n time you outpace the icicle enough that\n\n it has disappeared from the screen, but doing\n\n that will make you fly faster. If you need to\n\n take a break, you can press Escape to pause\n\n the game.", { 30.0f, static_cast<float>(ScreenHeight / 4) - 20 }, 25, 1.0f, BLUE);
    }

    DrawTextEx(font, "Go Back", { (30.0f), static_cast<float>(ScreenHeight - 20) }, 20, 1.0f, BLUE);
    DrawTextEx(font, "Play Game", { static_cast<float>(ScreenWidth - 150), static_cast<float>(ScreenHeight - 20) }, 20, 1.0f, BLUE);
    if (mousePos.y <= screenHeight && mousePos.y >= ScreenHeight - 40)
    {
        if (mousePos.x <= (ScreenWidth / 6))
        {
            DrawTextEx(font, "Go Back", { (30.0f), static_cast<float>(ScreenHeight - 20) }, 20, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {

                menu = Main;
            }
        }
        if (mousePos.x >= ScreenWidth - 140)
        {
            DrawTextEx(font, "Play Game", { static_cast<float>(ScreenWidth - 150), static_cast<float>(ScreenHeight - 20) }, 20, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                
                
                Gameplay::inIt(multiplayer);
                
                menu = Game;
            }
        }
    }
   


}

void playerSelect(Menu& menu)
{
    int ScreenWidth = GetScreenWidth();
    int ScreenHeight = GetScreenHeight();
    Vector2 mousePos = GetMousePosition();

    ClearBackground(RAYWHITE);

    DrawTextEx(font, "Select number of players:", {static_cast<float>(ScreenWidth / 2) - 220, static_cast<float>(ScreenHeight / 2) - 50}, 30, 1.0f, BLUE);
    DrawTextEx(font, "1", { static_cast<float>(ScreenWidth / 2) - 40, static_cast<float>((ScreenHeight / 2) + 40) }, 30, 1.0f, BLUE);
    DrawTextEx(font, "2", { static_cast<float>(ScreenWidth / 2) + 40, static_cast<float>((ScreenHeight / 2) + 40) }, 30, 1.0f, BLUE);
    if (mousePos.y <= ((screenHeight / 2) + 40) + 15 && mousePos.y >= ((screenHeight / 2) + 40) - 15)
    {
        if (mousePos.x < ((ScreenWidth / 2)) && mousePos.x >= ((ScreenWidth / 2) - 100))
        {
            
            DrawTextEx(font, "1", { static_cast<float>(ScreenWidth / 2) - 40, static_cast<float>((ScreenHeight / 2) + 40) }, 30, 1.0f, RED);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                multiplayer = false;    
                menu = Tutorial;
            }
        }
        else if (mousePos.x > ((ScreenWidth / 2)) && mousePos.x <= ((ScreenWidth / 2) + 100))
        {
            DrawTextEx(font, "2", { static_cast<float>(ScreenWidth / 2) + 40, static_cast<float>((ScreenHeight / 2) + 40) }, 30, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                multiplayer = true;
                menu = Tutorial;
            }
        }

    }
   
}



void titleMenu(Menu& menu)
  {
    int ScreenWidth = GetScreenWidth();
    int ScreenHeight = GetScreenHeight();

    ClearBackground(RAYWHITE);

    DrawTextEx(font, "Neo Migration", { (static_cast<float>(ScreenWidth) / 2) - 110, (static_cast<float>(ScreenHeight) / 2) - 30 }, 30, 1.0f, BLUE);
    DrawTextEx(font, "Press any key to continue...", { (static_cast<float>(ScreenWidth) / 2) - 140, (static_cast<float>(ScreenHeight) / 2) + 30 }, 20, 1.0f, BLUE);
    

    if (GetKeyPressed() >= 32 && GetKeyPressed() <= 168 || IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) || IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
    {
        multiplayer = false;
        menu = Main;
    }

   
  }

void creditsMenu(Menu& menu)
{
    int ScreenWidth = GetScreenWidth();
    int ScreenHeight = GetScreenHeight(); 
    Vector2 mousePos = GetMousePosition();

    ClearBackground(RAYWHITE);

#if _DEBUG
    DrawRectangle(((ScreenWidth / 2) + 15), ((ScreenHeight / 2) - 45), 320, 30, RED);
    DrawRectangle(((ScreenWidth / 2) +55), ((ScreenHeight / 2) - 10), 220, 30, RED);
    DrawRectangle(((ScreenWidth / 2) +45), ((ScreenHeight / 2) + 30), 240, 30, RED);
    DrawRectangle(((ScreenWidth / 2) - 40 ), ((ScreenHeight / 2) + 75), 200, 30, RED);
#endif // _DEBUG



    DrawTextEx(font, "Sprite/Backgrounds/Code by Joan Manuel Rivas Cepeda", { static_cast<float>(ScreenWidth / 8) - 50, static_cast<float>(ScreenHeight / 2) - 40 }, 20, 1.0f, BLUE);
    DrawTextEx(font, "TitleScreen/Game musics by Alfred Grupstra", { static_cast<float>(ScreenWidth / 5)-50, static_cast<float>(ScreenHeight / 2) }, 20, 1.0f, BLUE);
    DrawTextEx(font, "Sound Effects by the site The Motion Monkey", { static_cast<float>(ScreenWidth / 5) -40, static_cast<float>(ScreenHeight / 2) + 40 }, 20, 1.0f, BLUE);
    DrawTextEx(font, "Font by Vladimir Nikolic", { static_cast<float>(ScreenWidth / 3), static_cast<float>(ScreenHeight / 2) + 80 }, 20, 1.0f, BLUE);
    DrawTextEx(font, "Go Back", { (30.0f), static_cast<float>(ScreenHeight - 20) }, 20, 1.0f, BLUE);
    DrawTextEx(font, "Play Game", { static_cast<float>(ScreenWidth - 150), static_cast<float>(ScreenHeight - 20) }, 20, 1.0f, BLUE);

    if (mousePos.x >= ((ScreenWidth / 2) + 15) && mousePos.x <= (((ScreenWidth / 2) + 15) + 320))
    {
        if (mousePos.y >= ((ScreenHeight / 2) - 45) && mousePos.y <= ((ScreenHeight / 2) - 45) + 30)
        {
            DrawTextEx(font, "Sprite/Backgrounds/Code by Joan Manuel Rivas Cepeda", { static_cast<float>(ScreenWidth / 8) - 50, static_cast<float>(ScreenHeight / 2) - 40 }, 20, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                OpenURL("https://joan-mrc.itch.io");
            }
        }
    }

    if (mousePos.x >= ((ScreenWidth/2) - 40) && mousePos.x <= ((ScreenWidth / 2) - 40)+200)
    {
        if (mousePos.y >= ((ScreenHeight / 2) + 75) && mousePos.y <= ((ScreenHeight / 2) + 75)+30)
        {
            DrawTextEx(font, "Font by Vladimir Nikolic", { static_cast<float>(ScreenWidth / 3), static_cast<float>(ScreenHeight / 2) + 80 }, 20, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                OpenURL("https://www.dafont.com/es/vladimir-nikolic.d6875");
            }
        }
    }
    

    if (mousePos.x >= ((ScreenWidth / 2) + 55) && mousePos.x <=  ((ScreenWidth / 2) + 55) + 220)
    {
        if (mousePos.y >= ((ScreenHeight / 2) - 10) && mousePos.y <= ((ScreenHeight / 2) - 10) + 30)
        {
            DrawTextEx(font, "TitleScreen/Game musics by Alfred Grupstra", { static_cast<float>(ScreenWidth / 5) - 50, static_cast<float>(ScreenHeight / 2) }, 20, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                OpenURL("https://pixabay.com/users/alfred_grupstra-4379051/");
            }
        }
    }

    if (mousePos.x >= ((ScreenWidth / 2) + 45) && mousePos.x <= ((ScreenWidth / 2) + 45) +240)
    {
        if (mousePos.y >= ((ScreenHeight / 2) + 30) && mousePos.y <= ((ScreenHeight / 2) + 30) + 30)
        {
            DrawTextEx(font, "Sound Effects by the site The Motion Monkey", { static_cast<float>(ScreenWidth / 5) - 40, static_cast<float>(ScreenHeight / 2) + 40 }, 20, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                OpenURL("https://www.themotionmonkey.co.uk/free-resources/retro-arcade-sounds/");
            }
        }
    }



    if (mousePos.y <= screenHeight && mousePos.y >= ScreenHeight - 40)
    {
        if (mousePos.x <= (ScreenWidth / 6) )
        {
            DrawTextEx(font, "Go Back", { (30.0f), static_cast<float>(ScreenHeight - 20) }, 20, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                multiplayer = false;
                menu = Main;
            }
        }
        if (mousePos.x >= ScreenWidth - 140)
        {
            DrawTextEx(font, "Play Game", { static_cast<float>(ScreenWidth - 150), static_cast<float>(ScreenHeight - 20) }, 20, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                
                menu = NumberPlayers;
            }
        }
    }
    
}

 void mainMenu(Menu& menu)
 {
    Vector2 mousePos = GetMousePosition();
    int ScreenWidth = GetScreenWidth();
    int ScreenHeight = GetScreenHeight();
    

    ClearBackground(RAYWHITE);

    DrawTextEx(font, "Neo Migration", { (static_cast<float>(ScreenWidth) / 2) - 110, (static_cast<float>(ScreenHeight) / 2) - 30 }, 30, 1.0f, BLUE);
    DrawTextEx(font, "Play", { (static_cast<float>(ScreenWidth) / 2) - 20, (static_cast<float>(ScreenWidth) / 2) - 65 }, 20, 1.0f, BLUE);
    DrawTextEx(font, "Credits", { (static_cast<float>(ScreenWidth) / 2) - 40,   (static_cast<float>(ScreenWidth) / 2) - 35 }, 20, 1.0f, BLUE);
    DrawTextEx(font, "Exit", { (static_cast<float>(ScreenWidth) / 2) - 20, (static_cast<float>(ScreenHeight) / 2) + 100 }, 20, 1.0f, BLUE);

    if (mousePos.x <= ((ScreenWidth / 2) +50) && mousePos.x >= ((ScreenWidth / 2) - 50))
    {
        if (mousePos.y <= ((screenHeight/2)+30)+12 && mousePos.y >= ((screenHeight / 2)+30) - 12)
        {
            DrawTextEx(font, "Play", { (static_cast<float>(ScreenWidth) / 2) - 20, (static_cast<float>(ScreenWidth) / 2) - 65 }, 20, 1.0f, RED);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Gameplay::inIt(multiplayer);
                menu = NumberPlayers;
            }
        }
        
        if (mousePos.y <= ((screenHeight / 2) + 65) + 12 && mousePos.y >= ((screenHeight / 2) + 65) - 12)
        {
            DrawTextEx(font, "Credits", { (static_cast<float>(ScreenWidth) / 2) - 40,   (static_cast<float>(ScreenWidth) / 2) - 35}, 20, 1.0f, RED);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                menu = Credits;
            }
        }
       
        if (mousePos.y <= ((screenHeight / 2) + 100) + 12 && mousePos.y >= ((screenHeight / 2) + 100) - 12)
        {
            DrawTextEx(font, "Exit", { (static_cast<float>(ScreenWidth) / 2) - 20, (static_cast<float>(ScreenHeight) / 2) + 100 }, 20, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                unloadAll();
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

    
    
   
    
 }

 void drawPause(bool& ispaused)
 {
     int screenHeight = GetScreenHeight();
     int screenWidth = GetScreenWidth();
     Vector2 mousePos = GetMousePosition();

     if (ispaused == true)
     {
        
         DrawRectangle((screenWidth / 4), (screenHeight / 4), 400, 300, BLACK);
         DrawTextEx(font, "PAUSED", { (static_cast<float>(screenWidth) / 2) - 75, (static_cast<float>(screenHeight / 4) + 60) }, 40, 1.0f, WHITE);
         DrawTextEx(font, "Resume", { (static_cast<float>(screenWidth) / 2) - 45, (static_cast<float>(screenWidth)/2) - 90 }, 20, 1.0f, WHITE);
         DrawTextEx(font, "Return to Main Menu", { (static_cast<float>(screenWidth) / 2) - 115, (static_cast<float>(screenWidth) / 2) - 55 }, 20, 1.0f, WHITE);
         DrawTextEx(font, "Exit Game", { (static_cast<float>(screenWidth) / 2) - 55, (static_cast<float>(screenHeight) / 2) +80 }, 20, 1.0f, WHITE);
         if (mousePos.x <= screenWidth / 2+ 120 && mousePos.x >= screenWidth / 2 - 120)
         {
             if (mousePos.y >= ((screenHeight/2) -19) && mousePos.y <= ((screenHeight/2)+19))
             {
                 DrawTextEx(font, "Resume", { (static_cast<float>(screenWidth) / 2) - 45, (static_cast<float>(screenWidth)/2) -90 }, 20, 1.0f, RED);
                 if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                 {
                     ispaused = false;
                 }
             }
             if (mousePos.y >= ((screenHeight / 2) + 40) - 19 && mousePos.y <= ((screenHeight / 2) + 40) + 19)
             {
                 DrawTextEx(font, "Return to Main Menu", { (static_cast<float>(screenWidth) / 2) - 115, (static_cast<float>(screenWidth) / 2) - 55 }, 20, 1.0f, RED);
                 if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                 {
                     
                     menu = Main;
                     multiplayer = false;
                     ispaused = false;
                     
                 }
             }
             if (mousePos.y >= ((screenHeight / 2) + 80) -19 && mousePos.y <= ((screenHeight / 2) + 80) + 19)
             {
                 DrawTextEx(font, "Exit Game", { (static_cast<float>(screenWidth) / 2) - 55, (static_cast<float>(screenHeight) / 2) + 80 }, 20, 1.0f, RED);
                 if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                 {
                     unloadAll();
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


         Gameplay::draw(multiplayer);

         if (Gameplay::isGameOver(multiplayer) == true)
         {

             if (Gameplay::gameOverScreen(multiplayer) == 1)
             {

                 menu = Main;
             }
         }
         else if (Gameplay::isGameOver(multiplayer) == false)
         {


             drawPause(pausedGame);
             if (IsKeyPressed(KEY_ESCAPE))
             {
                 pausedGame = true;

             }
             if (pausedGame == false)
             {
                 Gameplay::update(multiplayer);
                 Gameplay::checkInput(multiplayer);

             }
         }


         break;
     case Game::NumberPlayers:
         playerSelect(menu);
         break;
     case Game::Tutorial:
         tutorial(multiplayer);
         break;
     default:
         break;
     }

     EndDrawing();

     if (menu != Game)
     {
         DrawTextEx(font, "1.0", { static_cast<float>(GetScreenWidth()) - MeasureText("0.1", 20) * 2, static_cast<float>(MeasureText("0.2", 20)) }, 20, 1.0f, BLACK);
     }

    

}

 void runGame()
{
    
    menu = Title;
    
    
    srand((unsigned int)time(NULL));
    InitWindow(screenWidth, screenHeight, "Neo Migration");
    SetExitKey(NULL);
    InitAudioDevice();
   titleMusic = LoadMusicStream("res/sounds/music/title.mp3");
   gameMusic = LoadMusicStream("res/sounds/music/gameplay.mp3");
   font = LoadFontEx("res/font/icecold.ttf", 32, 0, 250);
    
    
    
    

    

    while (!WindowShouldClose())
    {
        SetMusicVolume(titleMusic, 0.01f);
        SetMusicVolume(gameMusic, 0.01f);
        if (menu == Game)
        {
           
            if (GetMusicTimePlayed(gameMusic) <= 0)
            {
                PlayMusicStream(gameMusic);
            }
            else if (GetMusicTimePlayed(gameMusic) >= GetMusicTimeLength(gameMusic))
            {
                PlayMusicStream(gameMusic);
            }
           
            UpdateMusicStream(gameMusic);
        }
        else 
        {
            
            if (GetMusicTimePlayed(titleMusic) <= 0)
            {
                PlayMusicStream(titleMusic);
            }
            else if (GetMusicTimePlayed(titleMusic) >= GetMusicTimeLength(titleMusic))
            {
                PlayMusicStream(titleMusic);
            }

            UpdateMusicStream(titleMusic);
        }
        

       
        drawNupdate();

    }
    

    
    
    unloadAll();
    CloseAudioDevice();
    
   
    CloseWindow();
}


}