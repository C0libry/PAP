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
	GameUpdater();
	GameUpdater(const GameUpdater&) = delete;
	GameUpdater& operator=(GameUpdater const&);
public:
	static GameUpdater& getInstance();
	static void loadGame();
	void render(RenderWindow& window);
	bool update(Event event);
	void eventUpdate(Event& event);
};