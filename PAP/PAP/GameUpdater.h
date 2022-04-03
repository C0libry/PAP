#pragma once

#include "Include.h"
#include "Player.h"
#include "Slime.h"
#include "Camera.h"

class GameUpdater
{
	// �������� ������� ���� ��������� ������ ���� � ������� � main.cpp
private:
	//virtual ~GameUpdater() = 0;
	//Player h;
	//Base * hero;
	//Base* slime;
public:
	static void loadGame();
	void render(RenderWindow& window);
	void update(Event event);
	void eventUpdate(Event& event);
};

