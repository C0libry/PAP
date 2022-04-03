#pragma once

#include "Include.h"
#include "Player.h"
#include "Slime.h"
#include "Camera.h"

class GameUpdater
{
	// Возможно переесу сюда обновлени кадров игры и рыендер и main.cpp
private:
	//virtual ~GameUpdater() = 0;
	//Base * hero;
	//Base* slime;
public:
	GameUpdater();
	static void loadGame();
	void render(RenderWindow& window);
	void update(Event event);
	bool eventUpdate(Event& event, RenderWindow& window);
};