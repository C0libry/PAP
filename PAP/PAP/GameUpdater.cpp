#include "GameUpdater.h"

Int64 GameUpdater::gameTime = 0;
Clock deltaClock;

Player hero(PLAYER, IntRect(0, 0, 50, 37), Vector2f(0, 0));
vector <Slime> enemies;
vector <HellHound> hellHounds;
View camera = Camera::load();

void GameUpdater::loadGame()
{
	Loader::startLoad();
	Map::load();
	enemies.push_back(Slime(SLIME, IntRect(0, 0, 32, 25), Vector2f(400, 300), hero));
	enemies.push_back(Slime(SLIME, IntRect(0, 0, 32, 25), Vector2f(200, 200), hero));
	hellHounds.push_back(HellHound(HELL_HOUND_IDLE, IntRect(0, 0, 64, 32), Vector2f(150, 100), hero));
}

GameUpdater& GameUpdater::getInstance()
{
	static GameUpdater instance;
	return instance;
}

GameUpdater::GameUpdater()
{
	GameUpdater::loadGame();
}

void GameUpdater::render(RenderWindow& window)
{
	Map::render(window);
	for (int i = 0; i < hellHounds.size(); i++)
		hellHounds[i].render(window);

	for(int i = 0; i < enemies.size(); i++)
		enemies[i].render(window);

	hero.render(window);
	Camera::render(camera, window);
	Interface::interface(window, hero.getHP(), hero.getCoins());
}
bool GameUpdater::update(Event event)
{
	gameTime = deltaClock.getElapsedTime().asMilliseconds();
	hero.update(event);
	Map::update(event);
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].update(event);
		if (enemies[i].getHP() <= 0)
		{
			if (!enemies.empty())
				enemies.erase(enemies.begin() + i);
		}
	}

	for (int i = 0; i < hellHounds.size(); i++)
	{
		hellHounds[i].update(event);
		if (hellHounds[i].getHP() <= 0)
		{
			if (!hellHounds.empty())
				hellHounds.erase(hellHounds.begin() + i);
		}
	}

	Camera::move(camera, hero.getCentrePosition());
	return hero.isLife();
}
void GameUpdater::eventUpdate(Event& event)
{
	Camera::scrolle(camera, event);
}

Vector2f GameUpdater::getScreenCentre()
{
	return camera.getCenter();
}

Int64 GameUpdater::getGameTime()
{
	return gameTime;
}

void GameUpdater::setGameTime(Int64 GameTime)
{
	gameTime = GameTime;
}