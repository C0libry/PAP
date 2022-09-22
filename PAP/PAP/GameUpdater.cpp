#include "GameUpdater.h"

static Int64 GameTime = 0;
Clock deltaClock;

//GameUpdater::~GameUpdater() {};
Player hero(PLAYER, IntRect(0, 0, 50, 37), Vector2f(0, 0));
vector <Slime> enemies;
View camera = Camera::load();

void GameUpdater::loadGame()
{
	Loader::startLoad();
	Map::load();
	enemies.push_back(Slime(SLIME, IntRect(0, 0, 32, 25), Vector2f(400, 300), hero));
	enemies.push_back(Slime(SLIME, IntRect(0, 0, 32, 25), Vector2f(200, 200), hero));
	//hero.loadEnemys(slime);
}

//void GameUpdater::loadEnemys()

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
	for(int i = 0; i < enemies.size(); i++)
		enemies[i].render(window);
	hero.render(window);
	Camera::render(camera, window);
	Interface::interface(window, hero.getHP());
}
bool GameUpdater::update(Event event)
{
	GameTime = deltaClock.getElapsedTime().asMilliseconds();
	int delay = 1 * 1000;
	hero.update(event);
	for (int i = 0; i < enemies.size(); i++)
	{
		enemies[i].update(event);
		if (hero.getHitBox().intersects(enemies[i].getAttackHitBox()))
		{
			if (enemies[i].getTimer() + delay < GameTime)
			{
				hero.setHP(hero.getHP() - enemies[i].gerStrength());
				enemies[i].setTimer(GameTime);
			}
		}
		if (hero.getIsAttack())
		{
			if (hero.getAttackHitBox().intersects(enemies[i].getHitBox()))
			{
				enemies[i].setHP(enemies[i].getHP() - hero.gerStrength());
			}
		}
		if (enemies[i].getHP() <= 0)
		{
			if (!enemies.empty())
				enemies.erase(enemies.begin()+i);
		}
	}
	Camera::move(camera, hero.getCentrePosition());
	//Camera::move(camera, hero.getSprite().getPosition());
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