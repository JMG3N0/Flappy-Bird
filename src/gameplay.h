#pragma once



namespace Gameplay
{
	
	void inIt(bool multiplayer);
	void checkInput(bool multiplayer);
	void update(bool multiplayer);
	void draw(bool multiplayer);
	void unload(bool multiplayer);
	bool isGameOver(bool multiplayer);
	int gameOverScreen(bool multiplayer);

}