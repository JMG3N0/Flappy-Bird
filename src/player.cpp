#include "player.h"

void Player::inItPlayer(Player& player)
{
	player.hitBox.x = static_cast<float>(GetScreenWidth() / 4);
	player.hitBox.y = static_cast<float>(GetScreenHeight() / 2);
	player.initPos = {player.hitBox.x, player.hitBox.y};
	player.hitBox.width = 62;
	player.hitBox.height = 32;
	player.speed = 50;
	player.initSpeed = 50;
	player.jumpForce = -150.f;
	player.frameNumber = 0;
	player.score = 0;
	if (player.hasHiScore == false)
	{

		player.hiScore = 0;
	}
	player.gameOver = false;

	player.sprite = LoadTexture("res/player.png");

}

void Player::drawPlayer(Player player, Color colors)
{
#if _DEBUG
	DrawRectangle(static_cast<int>(player.hitBox.x), static_cast<int>(player.hitBox.y), static_cast<int>(player.hitBox.width), static_cast<int>(player.hitBox.height), BLUE);
#endif // Debug
	if (player.frameNumber == 0 || player.frameNumber == 2)
	{
		DrawTexturePro(player.sprite, { 0,0, static_cast<float>(player.sprite.width), (static_cast<float>(player.sprite.height)/2) }, player.hitBox, { 0,0 }, 0, colors);
	}
	if (player.frameNumber == 1)
	{
		DrawTexturePro(player.sprite, { 0,16, static_cast<float>(player.sprite.width), (static_cast<float>(player.sprite.height)/2) }, player.hitBox, { 0,0 }, 0, colors);
	}
	
	
}

void Player::movePlayer(Player& player)
{
	float gravity = 200.0f;

	

	if (player.speed >= 0)
	{
		player.frameNumber = 0;
	}
	if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP) )
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
}

void Player::unload(Player& player)
{
	UnloadTexture(player.sprite);
}


void Player::showScore(Player player)
{
	int screenHeight = GetScreenHeight();
	int screenWidth = GetScreenWidth();
	DrawText(TextFormat("%d", player.score), (screenWidth / 2), (screenHeight / 2) - 80, 40, WHITE);

}