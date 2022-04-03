#include "main.h"

static Int64 timer = 0;

void click(Event& event, int& count, bool& KeyPressed)
{
	//Проверка на отпускание кнопки
	if (event.type == Event::KeyReleased)
	{
		if (event.key.code == Keyboard::Escape)
		{
			KeyPressed = false;
		}
	}
	
	//Проверка на нажатие кнопки
	if (event.type == Event::KeyPressed && !KeyPressed)
	{
		if (event.key.code == Keyboard::Escape)
		{
			KeyPressed = true;
			count++;
			cout << count << ")Escape Pressed\n";
		}
	}
}

void clickWithCooldown(Event& event, int& count, bool& KeyPressed, Int64& allTime, float delay)
{
	if (allTime > timer + delay)
	{
		KeyPressed = false;
	}

	if (event.type == Event::KeyPressed && !KeyPressed)
	{
		if (event.key.code == Keyboard::Escape)
		{
			KeyPressed = true;
			count++;
			timer = allTime;
			cout << count << ")Escape Pressed\n";
			cout << count << ")allTime = " << (allTime/1000/1000) << endl;
		}
	}
}

int main()
{
	GameUpdater gameUpdater;
	GameUpdater::loadGame();

	RenderWindow window(sf::VideoMode(960, 540), "Platformer");
	//RenderWindow window(sf::VideoMode(960, 540), "Platformer", Style::Fullscreen);

	Clock deltaClock;

	//Level level;
	//level.LoadFromFile("map.tmx");

	while (window.isOpen())
	{
		//Base::setDeltaTime(deltaClock.getElapsedTime().asMicroseconds() / 1000.f);
		cout << "DeltaTime = " << Base::getDeltaTime() << endl;

		Base::setDeltaTime(deltaClock.restart().asMicroseconds() / 1000.f);

		deltaClock.restart();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			gameUpdater.eventUpdate(event);
			//clickWithCooldown(event, count, KeyPressed, allTime, (3 * 1000 * 1000));
		}
		gameUpdater.update(event);
		window.clear();
		gameUpdater.render(window);
		window.display();
	}

	return 0;
}
