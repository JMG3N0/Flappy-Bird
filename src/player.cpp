#include "player.h"

void Player::inItPlayer(Player& player)
{
	player.hitBox.x = static_cast<float>(GetScreenWidth() / 4);
	player.hitBox.y = static_cast<float>(GetScreenHeight() / 2);
	player.initPos = {player.hitBox.x, player.hitBox.y};
	player.hitBox.width = 62;
	player.hitBox.height = 32;
	player.speed = 100;
	player.initSpeed = 100;
	player.jumpForce = -250.f;
	player.frameNumber = 0;
	player.score = 0;
	if (player.hasHiScore == false)
	{

		player.hiScore = 0;
	}
	player.gameOver = false;
	player.active = true;
	player.sprite = LoadTexture("res/player.png");

}

void Player::drawPlayer(Player player, Color colors)
{
#if _DEBUG
	DrawRectangle(static_cast<int>(player.hitBox.x), static_cast<int>(player.hitBox.y), static_cast<int>(player.hitBox.width), static_cast<int>(player.hitBox.height), BLUE);
#endif // Debug
	if (player.gameOver == false)
	{


		if (player.frameNumber == 0 || player.frameNumber == 2)
		{
			DrawTexturePro(player.sprite, { 0,0, static_cast<float>(player.sprite.width), (static_cast<float>(player.sprite.height) / 2) }, player.hitBox, { 0,0 }, 0, colors);
		}
		if (player.frameNumber == 1)
		{
			DrawTexturePro(player.sprite, { 0,16, static_cast<float>(player.sprite.width), (static_cast<float>(player.sprite.height) / 2) }, player.hitBox, { 0,0 }, 0, colors);
		}
	}
	
}

void Player::movePlayer(Player& player, Player& player2, bool multiplayer)
{
	float gravity = 500.0f;

	if (multiplayer == true)
	{
		if (player2.speed >= 0)
		{
			player2.frameNumber = 0;
		}

		if (IsKeyPressed(KEY_UP) && player2.gameOver == false)
		{

			if (player2.frameNumber == 1)
			{
				player2.frameNumber = 0;
			}
			else
			{
				player2.speed = player2.jumpForce;
				player2.frameNumber = 1;
			}

		}
		player2.speed += gravity * GetFrameTime();

		player2.hitBox.y += player2.speed * GetFrameTime();
		if (player2.hitBox.y < 0)
		{
			player2.hitBox.y = 0;
		}
	}
	

	if (player.speed >= 0)
	{
		player.frameNumber = 0;
	}
	if (IsKeyPressed(KEY_W) && player.gameOver == false)
	{
		
			
		
		

		if (player.frameNumber == 1)
		{
			player.frameNumber = 0;
		}
		else
		{
			player.speed = player.jumpForce;
			player.frameNumber = 1;
		}
		
	}
	player.speed += gravity * GetFrameTime();
	
	player.hitBox.y += player.speed * GetFrameTime();
	if (player.hitBox.y < 0)
	{
		player.hitBox.y = 0;
	}
}



void Player::restartPlayer(Player& player)
{
	player.hitBox.x = player.initPos.x;
	player.hitBox.y = player.initPos.y;
	player.speed = player.initSpeed;
	//player.gameOver = false;
	
}

void Player::unload(Player& player)
{
	UnloadTexture(player.sprite);
	
}


void Player::showScore(Player player, Player player2, bool mult)
{
	int screenHeight = GetScreenHeight();
	int screenWidth = GetScreenWidth();
	if (mult == false)
	{
		DrawText(TextFormat("%d", player.score), (screenWidth / 2), (screenHeight / 2) - 80, 40, WHITE);
	}
	else
	{
		DrawText(TextFormat("%d", player.score), ((screenWidth / 2) - 60), (screenHeight / 2) - 80, 40, RED);
		DrawText(TextFormat("%d", player2.score), ((screenWidth / 2) + 60), (screenHeight / 2) - 80, 40, BLUE);
	}
	

}