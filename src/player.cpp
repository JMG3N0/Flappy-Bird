#include "player.h"

void Player::inItPlayer(Player& player)
{
	player.hitBox.x = static_cast<float>(GetScreenWidth() / 4);
	player.hitBox.y = static_cast<float>(GetScreenHeight() / 2);
	player.initPos = {player.hitBox.x, player.hitBox.y};
	player.hitBox.width = 20;
	player.hitBox.height = 20;
	player.speed = 50;
	player.initSpeed = 50;
	player.jumpForce = -100.f;
}

void Player::drawPlayer(Player player)
{
	DrawRectangle(player.hitBox.x, player.hitBox.y, player.hitBox.width, player.hitBox.height, BLUE);
}

void Player::movePlayer(Player& player)
{
	float gravity = 100.0f;
	if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
	{
		player.speed = player.jumpForce;
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
	player.hitBox = {player.initPos.x, player.initPos.y};
	player.speed = player.initSpeed;
}