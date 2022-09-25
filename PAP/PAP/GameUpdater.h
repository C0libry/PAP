#pragma once

#include "Include.h"
#include "Base.h"
#include "Player.h"
#include "Slime.h"
#include "HellHound.h"
#include "Camera.h"
#include "Interface.h"

class GameUpdater
{
private:
	//virtual ~GameUpdater() = 0;
	//Base * hero;
	//Base* slime;
	static Int64 gameTime;
	GameUpdater();
	GameUpdater(const GameUpdater&) = delete;
	GameUpdater& operator=(GameUpdater const&);
public:
	static GameUpdater& getInstance();
	static void loadGame();
	void render(RenderWindow& window);
	bool update(Event event);
	void eventUpdate(Event& event);
	static Vector2f getScreenCentre();
	static Int64 getGameTime();
	static void setGameTime(Int64 GameTime);
};