#include "GameUpdater.h"

//GameUpdater::~GameUpdater() {};
Player hero(PLAYER, IntRect(0, 0, 50, 37), Vector2f(0, 0));
Slime slime(SLIME, IntRect(0, 0, 32, 25), Vector2f(500, 300), hero);
View camera = Camera::load();

void GameUpdater::loadGame()
{
	Loader::startLoad();
	Map::load();
}

void GameUpdater::render(RenderWindow& window)
{
	Map::render(window);
	slime.render(window);
	hero.render(window);
	Camera::render(camera, window);
}
void GameUpdater::update(Event event)
{
	hero.update(event);
	slime.update(event);
	Camera::move(camera, hero.getSprite().getPosition());
}
void GameUpdater::eventUpdate(Event& event)
{
	Camera::scrolle(camera, event);
}