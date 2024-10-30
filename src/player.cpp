#include "player.h"

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
	if (IsKeyDown(KEY_W))
	{
		player.hitBox.y -= player.speed * GetFrameTime();
	}
	if (IsKeyDown(KEY_S))
	{
		player.hitBox.y += player.speed * GetFrameTime();
	}
}