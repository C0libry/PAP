#include "main.h"

static Int64 timer = 0;

void click(Event& event, int& count, bool& KeyPressed)
{
	//�������� �� ���������� ������
	if (event.type == Event::KeyReleased)
	{
		if (event.key.code == Keyboard::Escape)
		{
			KeyPressed = false;
		}
	}
	
	//�������� �� ������� ������
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
	Loader::startLoad();

	Map::load();

	//Tile tile(box, IntRect(0, 0, 16, 16), Vector2f(300, 300));

	RenderWindow window(sf::VideoMode(960, 540), "Platformer");
	//RenderWindow window(sf::VideoMode(960, 540), "Platformer", Style::Fullscreen);

	View camera = Camera::load();

	Player hero(PLAYER, IntRect(0, 0, 50, 37), Vector2f(0, 0));
	cout << &hero << " ";
	Slime slime(Objects::SLIME, IntRect(0, 0, 32, 25), Vector2f(500, 300), hero);

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

			Camera::scrolle(camera, event);

			//hero.eventUpdate(event, time);
			//clickWithCooldown(event, count, KeyPressed, allTime, (3 * 1000 * 1000));
		}
		hero.update(event);
		slime.update(event);

		window.clear();

		Map::render(window);
		slime.render(window);
		hero.render(window);
		Camera::move(camera, hero.getSprite().getPosition());
		Camera::render(camera, window);

		window.display();
	}

	return 0;
}
