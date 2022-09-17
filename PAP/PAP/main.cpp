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
	RenderWindow window(sf::VideoMode(960, 540), "Platformer");
	//RenderWindow window(sf::VideoMode(960, 540), "Platformer", Style::Fullscreen);
	//window.setMouseCursorVisible(false);
	//Level level;
	//level.LoadFromFile("map.tmx");
	Int64 frame_duration;
	Int64 time_to_sleep;
	float want_fps = 60.f;
	Clock deltaClock;
	Base::setDeltaTime(10.f);
	Interface::mainMenu(window);
	while (window.isOpen())
	{
		//Base::setDeltaTime(deltaClock.getElapsedTime().asMicroseconds() / 1000.f);
		//cout << "DeltaTime = " << Base::getDeltaTime() << endl;
		//deltaClock.restart();
		//Base::setDeltaTime(deltaClock.restart().asMicroseconds() / 1000.f);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				Interface::paus(window);
			GameUpdater::getInstance().eventUpdate(event);
			//clickWithCooldown(event, count, KeyPressed, allTime, (3 * 1000 * 1000));
		}

		if (!GameUpdater::getInstance().update(event))
			window.close();
		window.clear();
		GameUpdater::getInstance().render(window);
		window.display();

		frame_duration = deltaClock.restart().asMicroseconds();
		time_to_sleep = Int64(1000 * 1000.f / want_fps) - frame_duration;
		//cout << 1/((frame_duration + time_to_sleep)/ (1000 * 1000.f)) << endl;
		if (time_to_sleep > 0)
			sleep(microseconds(time_to_sleep));
	}
	return 0;
}
