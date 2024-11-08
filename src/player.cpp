#include "player.h"

void Player::inItPlayer(Player& player, Vector2 pos, float width, float height, float speed)
{
	player.hitBox.x = pos.x;
	player.hitBox.y = pos.y;
	player.hitBox.width = width;
	player.hitBox.height = height;
	player.speed = speed;
}

void Player::drawPlayer(Player player)
{
	DrawRectangle(player.hitBox.x, player.hitBox.y, player.hitBox.width, player.hitBox.height, BLUE);
}

void Player::movePlayer(Player& player)
{
	float gravity = 100.0f;
	float jumpForce = -100;
	if (IsKeyPressed(KEY_SPACE))
	{
		player.speed = jumpForce;
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
	player.hitBox.x = static_cast<float>(GetScreenWidth() / 4);
	player.hitBox.y = static_cast<float>(GetScreenHeight() / 2);
	player.speed = 50;
}