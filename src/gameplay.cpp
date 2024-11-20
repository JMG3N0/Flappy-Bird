#include "gameplay.h"

#include "raylib.h"

#include "player.h"
#include "obstacle.h"

namespace Gameplay
{
static Player::Player player;
static Player::Player player2;
static Obstacle::Obstacle obstacle;
static Sound fallDeath;
static Sound collisionDeath;
static Sound pointScore;
static Sound gameOver;
static Texture2D backGround;
static Texture2D foreGround;
static Texture2D midGround;
static Color colors;
static Font font;
static float backGroundSpeed;
static float midGroundSpeed;
static float foreGroundSpeed;
static bool dayToNight;



void Gameplay::inIt(bool multiplayer)
{

	

	Player::inItPlayer(player);
    if (multiplayer == true)
    {
        Player::inItPlayer(player2);
    }
	Obstacle::inItObstacle(obstacle);
    backGround = LoadTexture("res/scenario/Background.png");
    midGround = LoadTexture("res/scenario/Midground.png");
    foreGround = LoadTexture("res/scenario/Foreground.png");
    backGroundSpeed = 0.0f;
    midGroundSpeed = 0.0f;
    foreGroundSpeed = 0.0f;
    colors = { 255, 255, 255, 255 };
    dayToNight = true;
    gameOver = LoadSound("res/sounds/effects/GameOver.ogg");
    pointScore = LoadSound("res/sounds/effects/Point.ogg");
    collisionDeath = LoadSound("res/sounds/effects/Wall.ogg");
    fallDeath = LoadSound("res/sounds/effects/Fall.ogg");
    SetSoundVolume(gameOver, 0.01f);
    SetSoundVolume(pointScore, 0.01f);
    SetSoundVolume(fallDeath, 0.02f);
    SetSoundVolume(collisionDeath, 0.2f);
    font = LoadFontEx("res/font/icecold.ttf", 32, 0, 250);
}

void Gameplay::checkInput(bool multiplayer)
{
	Player::movePlayer(player, player2, multiplayer);
    
}

bool CheckCollision(Rectangle player, Rectangle freeSpace, Rectangle collisionSpace)
{
    Rectangle collisionTop = {collisionSpace.x, collisionSpace.y, collisionSpace.width, freeSpace.y};
    Rectangle collisionLow = {collisionSpace.x, (freeSpace.y+freeSpace.height), collisionSpace.width, collisionSpace.height};
    
        if (CheckCollisionRecs(player, collisionTop) || CheckCollisionRecs(player, collisionLow))
        {
            
            return true;
        }

        
    

   

    return false;
}

bool Gameplay::isGameOver(bool multiplayer)
{
    

    if (multiplayer == false)
    {
        if (player.gameOver == true)
        {
            
            return true;
        }
        else
        {
            
            return false;
        }
    }
    else
    {
        if (player.gameOver == true && player2.gameOver == true )
        {
            return true;
        }
        else if (player.gameOver == false || player2.gameOver == false)
        {
            return false;
        }
    }
    
}

int Gameplay::gameOverScreen(bool multiplayer)
{
    int screenHeight = GetScreenHeight();
    int screenWidth = GetScreenWidth();
    Vector2 mousePos = GetMousePosition();

    

    DrawRectangle((screenWidth / 4), (screenHeight / 4), 400, 300, BLACK);
    DrawTextEx(font, "Game Over", { static_cast<float>(screenWidth / 2) - 180, static_cast<float>(screenHeight / 4) + 20 }, 60, 1.0f, WHITE);
    if (multiplayer == true)
    {
        if (player.score > player2.score)
        {
            DrawTextEx(font, TextFormat("  P1 Score: %d", player.score), { static_cast<float>(screenWidth / 2) - 120, static_cast<float>(screenHeight / 2) - 60 }, 30, 1.0f, RED);
        }
        else if (player2.score > player.score)
        {
            DrawTextEx(font, TextFormat("  P2 Score: %d", player2.score), { static_cast<float>(screenWidth / 2) - 120, static_cast<float>(screenHeight / 2) - 60 }, 30, 1.0f, DARKBLUE);
        }
        else if (player.score == player2.score)
        {
            DrawTextEx(font, TextFormat("Your Score: %d", player.score), { static_cast<float>(screenWidth / 2) - 120, static_cast<float>(screenHeight / 2) - 60 }, 30, 1.0f, WHITE);
        }
        
    }
    else
    {
        DrawTextEx(font, TextFormat("Your Score: %d", player.score), { static_cast<float>(screenWidth / 2) - 120, static_cast<float>(screenHeight / 2) - 60 }, 30, 1.0f, WHITE);
    }
    DrawTextEx(font, TextFormat("High Score: %d", player.hiScore), { static_cast<float>(screenWidth / 2) - 90, static_cast<float>(screenHeight / 2) - 30 }, 25, 1.0f, WHITE);
    DrawTextEx(font, "Retry", { (static_cast<float>(screenWidth) / 2) - 30, (static_cast<float>(screenWidth) / 2) - 90 }, 20, 1.0f, WHITE);
    DrawTextEx(font, "Return to Main Menu", { (static_cast<float>(screenWidth) / 2) - 115, (static_cast<float>(screenWidth) / 2) - 55 }, 20, 1.0f, WHITE);
    DrawTextEx(font, "Exit Game", { (static_cast<float>(screenWidth) / 2) - 55, (static_cast<float>(screenHeight) / 2) + 80 }, 20, 1.0f, WHITE);
    if (mousePos.x <= screenWidth / 2 + 120 && mousePos.x >= screenWidth / 2 - 120)
    {
        if (mousePos.y >= ((screenHeight / 2) - 5) && mousePos.y <= ((screenHeight / 2) + 20))
        {
            DrawTextEx(font, "Retry", { (static_cast<float>(screenWidth) / 2) - 30, (static_cast<float>(screenWidth) / 2) - 90 }, 20, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                player.gameOver = false;
                if (multiplayer == true)
                {
                    player2.gameOver = false;
                    player.score = 0;
                }
                player.score = 0;
                
                return 0;
            }
        }
        if (mousePos.y >= ((screenHeight / 2) + 35) - 10 && mousePos.y <= ((screenHeight / 2) + 45) + 15)
        {
            DrawTextEx(font, "Return to Main Menu", { (static_cast<float>(screenWidth) / 2) - 115, (static_cast<float>(screenWidth) / 2) - 55 }, 20, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                
                return 1;
            }
        }
        if (mousePos.y >= ((screenHeight / 2) + 80) - 15 && mousePos.y <= ((screenHeight / 2) + 85) + 25)
        {
            DrawTextEx(font, "Exit Game", { (static_cast<float>(screenWidth) / 2) - 55, (static_cast<float>(screenHeight) / 2) + 80 }, 20, 1.0f, RED);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                
                CloseWindow();
            }
        }


    }

   /* if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        CloseWindow();
    }*/
}

void Gameplay::update(bool multiplayer)
{
    


        backGroundSpeed -= 0.01f;
        midGroundSpeed -= 0.05f;
        foreGroundSpeed -= 0.1f;

        if (backGroundSpeed <= -backGround.width * 2) backGroundSpeed = 0;
        if (midGroundSpeed <= -midGround.width) midGroundSpeed = 0;
        if (foreGroundSpeed <= -foreGround.width) foreGroundSpeed = 0;


        Obstacle::moveObstacle(obstacle);
        

        if (multiplayer == false)
        {


            if (CheckCollision(player.hitBox, obstacle.freeSpace, obstacle.collisionSpace) || player.hitBox.y + player.hitBox.height >= static_cast<float>(GetScreenHeight()))
            {
                if (player.hitBox.y + player.hitBox.height == static_cast<float>(GetScreenHeight()) - 1.0f)
                {
                    PlaySound(fallDeath);
                }
                if(CheckCollision(player.hitBox, obstacle.freeSpace, obstacle.collisionSpace))
                {
                    PlaySound(collisionDeath);
                }
                Player::restartPlayer(player);
                Obstacle::restartObstacle(obstacle);
                backGroundSpeed = 0.0f;
                midGroundSpeed = 0.0f;
                foreGroundSpeed = 0.0f;
                dayToNight = true;
                colors = { 255, 255, 255, 255 };
                if (player.score > player.hiScore)
                {
                    player.hiScore = player.score;
                    player.hasHiScore = true;
                }

                //  player.score = 0;
                player.gameOver = true;
                PlaySound(fallDeath);
                PlaySound(gameOver);
                obstacle.speed = obstacle.initSpeed;

            }
        }
            if (multiplayer == true)
            {

                if (CheckCollision(player.hitBox, obstacle.freeSpace, obstacle.collisionSpace) || player.hitBox.y + player.hitBox.height >= static_cast<float>(GetScreenHeight()))
                {
                    if (player.gameOver == false)
                    {
                        if (CheckCollision(player.hitBox, obstacle.freeSpace, obstacle.collisionSpace))
                        {
                            PlaySound(collisionDeath);
                        }
                    }
                    
                    
                    

                    if (player.score > player.hiScore)
                    {
                        player.hiScore = player.score;
                        player.hasHiScore = true;
                    }

                    //  player.score = 0;
                    player.gameOver = true;

                    

                }



                if (CheckCollision(player2.hitBox, obstacle.freeSpace, obstacle.collisionSpace) || player2.hitBox.y + player2.hitBox.height >= static_cast<float>(GetScreenHeight()))
                {
                    
                    if (player.gameOver == false)
                    {
                        if (CheckCollision(player2.hitBox, obstacle.freeSpace, obstacle.collisionSpace))
                        {
                            PlaySound(collisionDeath);
                        }
                    }

                    if (player2.score > player2.hiScore)
                    {
                        player2.hiScore = player2.score;
                        player2.hasHiScore = true;
                    }

                    //  player.score = 0;
                    if ( player2.hiScore > player.hiScore)
                    {
                        player.hiScore = player2.hiScore;
                    }
                    player2.gameOver = true;

                    

                }
                if (player.gameOver == true && player2.gameOver == true)
                {
                    PlaySound(fallDeath);
                    PlaySound(gameOver);
                    Player::restartPlayer(player);
                    Player::restartPlayer(player2);
                    Obstacle::restartObstacle(obstacle);
                    backGroundSpeed = 0.0f;
                    midGroundSpeed = 0.0f;
                    foreGroundSpeed = 0.0f;
                    dayToNight = true;
                    colors = { 255, 255, 255, 255 };
                }
            }
        
       
        


        if (obstacle.freeSpace.x <= 0)
        {
            if (dayToNight == true)
            {
                colors.b -= 5;
                colors.g -= 5;
                colors.r -= 5;
                if (colors.b <= 50)
                {
                    colors.b = 50;
                    colors.g = 50;
                    colors.r = 50;
                    dayToNight = false;
                }
            }
            else
            {
                colors.b += 5;
                colors.g += 5;
                colors.r += 5;
                if (colors.b >= 255)
                {
                    colors.b = 255;
                    colors.g = 255;
                    colors.r = 255;
                    dayToNight = true;
                }
            }

            Obstacle::restartObstacle(obstacle);

            if (player.gameOver == false)
            {
                PlaySound(pointScore);
                player.score++;
            }
            if (multiplayer == true)
            {
                if (player2.gameOver == false)
                {
                    PlaySound(pointScore);
                    player2.score++;
                }
            }
            if (obstacle.speed < 450)
            {
                obstacle.speed += 15;
            }
            
        }
        
    

    
}
void Gameplay::draw(bool multiplayer)
{
    int screenHeight = GetScreenHeight();
    int screenWidth = GetScreenWidth();


    DrawTextureEx(backGround, { backGroundSpeed,-100 }, 0.0f, 2.0f, colors);
    DrawTextureEx(backGround, { static_cast<float>(backGround.width * 2) + backGroundSpeed,-100 }, 0.0f, 2.0f, colors);
    
    DrawTextureEx(midGround, { midGroundSpeed, 100 }, 0.0f, 1.0f, colors);
    DrawTextureEx(midGround, {static_cast<float>(midGround.width) + midGroundSpeed,100}, 0.0f, 1.0f, colors);

    DrawTextureEx(foreGround, { foreGroundSpeed,70 }, 0.0f, 1.0f, colors);
    DrawTextureEx(foreGround, { static_cast<float>(foreGround.width) + foreGroundSpeed,70 }, 0.0f, 1.0f, colors);
    

    Obstacle::drawObstacle(obstacle, colors);
    if (multiplayer == true)
    {
        Player::drawPlayer(player, RED);
        Player::drawPlayer(player2, BLUE);
    }
    else
    {
        Player::drawPlayer(player, colors);
    }
    Player::showScore(player, player2, multiplayer);
    
   
}

void unload(bool multiplayer)
{
    Player::unload(player);
    if (multiplayer == true)
    {
        Player::unload(player2);
    }
    UnloadTexture(backGround);
    UnloadTexture(foreGround);
    UnloadTexture(midGround);
    UnloadSound(gameOver);
    UnloadSound(collisionDeath);
    UnloadSound(fallDeath);
    UnloadSound(pointScore);
    UnloadFont(font);
}
}