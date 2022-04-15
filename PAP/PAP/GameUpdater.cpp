#include "GameUpdater.h"

//GameUpdater::~GameUpdater() {};
Player hero(PLAYER, IntRect(0, 0, 50, 37), Vector2f(0, 0));
Slime slime(SLIME, IntRect(0, 0, 32, 25), Vector2f(500, 300), hero);
View camera = Camera::load();

void GameUpdater::loadGame()
{
	Loader::startLoad();
	Map::load();
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
	slime.render(window);
	hero.render(window);
	Camera::render(camera, window);
}
bool GameUpdater::update(Event event)
{
	hero.update(event);
	slime.update(event);
	//cout << hero.getHP() << endl;
	if (hero.getHitBox().intersects(slime.getAttackHitBox()))
	{
		hero.setHP(hero.getHP() - slime.gerStrength());
	}
	Camera::move(camera, hero.getCentrePosition());
	//Camera::move(camera, hero.getSprite().getPosition());
	return hero.isLife();
}
void GameUpdater::eventUpdate(Event& event)
{
	Camera::scrolle(camera, event);
}