#include "player.h"

extern const int screenWidth = 800;
extern const int screenHeight = 450;

void player::inItPlayer(Player& player, Vector2 pos, float width, float height, float speed)
{
	player.hitBox.x = pos.x;
	player.hitBox.y = pos.y;
	player.hitBox.width = width;
	player.hitBox.height = height;
	player.speed = speed;
}

void player::drawPlayer(Player player)
{
	DrawRectangle(player.hitBox.x, player.hitBox.y, player.hitBox.width, player.hitBox.height, BLUE);
}

void player::movePlayer(Player& player)
{
	float gravity = 100.0f;
	float jumpForce = -100;
	if (IsKeyPressed(KEY_SPACE))
	{
		player.speed = jumpForce;
	}
	player.speed += gravity * GetFrameTime();
	player.hitBox.y += player.speed * GetFrameTime();
}

void player::restartPlayer(Player& player)
{
	player.hitBox.x = static_cast<float>(screenWidth / 4);
	player.hitBox.y = static_cast<float>(screenHeight / 2);
	player.speed = 50;
}