#include "GameUpdater.h"

//GameUpdater::~GameUpdater() {};
Player hero(PLAYER, IntRect(0, 0, 50, 37), Vector2f(0, 0));
vector <Slime> enemies;
View camera = Camera::load();

void GameUpdater::loadGame()
{
	Loader::startLoad();
	Map::load();
	enemies.push_back(Slime(SLIME, IntRect(0, 0, 32, 25), Vector2f(500, 300), hero));
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
	if (!enemies.empty())
		enemies[0].render(window);
	hero.render(window);
	Camera::render(camera, window);
}
bool GameUpdater::update(Event event)
{
	hero.update(event);
	enemies[0].update(event);
	if (!enemies.empty())
	{
		if (hero.getHitBox().intersects(enemies[0].getAttackHitBox()))
		{
			hero.setHP(hero.getHP() - enemies[0].gerStrength());
		}
		if (hero.getIsAttack())
		{
			if (hero.getAttackHitBox().intersects(enemies[0].getHitBox()))
			{
				enemies[0].setHP(enemies[0].getHP() - hero.gerStrength());
			}
		}
		if (enemies[0].getHP() <= 0)
		{
			if (!enemies.empty())
				//enemies.pop_back();
				cout << "slime is dead";
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