#include "Interface.h"

void Interface::mainMenu(RenderWindow& window)
{
	bool game = false;
	Font font;
	font.loadFromFile("resources/font/PressStart2P-Regular.ttf");
	Text play("Play", font, 50);
	Text endGame("Exit", font, 50);
	play.setFillColor(Color::Yellow);

	int pointer = 1;
	int max = 2;


	play.setPosition(960 / 2 - play.getGlobalBounds().width / 2, 540 / 2 - play.getGlobalBounds().height / 2 - 50);
	endGame.setPosition(960 / 2 - endGame.getGlobalBounds().width / 2, 540 / 2 - endGame.getGlobalBounds().height / 2 + 50);
	//string s;
	while (window.isOpen())
	{
		play.setFillColor(Color::White);
		endGame.setFillColor(Color::White);

		if (pointer > max) pointer = 1;
		if (pointer < 1) pointer = max;

		switch (pointer)
		{
			case(1):
				play.setFillColor(Color::Yellow);
				break;
			case(2):
				endGame.setFillColor(Color::Yellow);
				break;
		default:
			break;
		}

		Event event;
		while (window.pollEvent(event))
		{
			if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W)))
			{
				pointer++;
			}

			if ((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S)))
			{
				pointer--;
			}
			if (event.type == sf::Event::Closed)
				window.close();

			GameUpdater::getInstance().eventUpdate(event);
		}

		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			switch (pointer)
			{
			case(1):
				game = true;
				break;
			case(2):
				window.close();
				break;
			default:
				break;
			}
		}
		if (game)
			break;

		window.clear();
		window.draw(play);
		window.draw(endGame);
		window.display();
	}
}

void Interface::paus(RenderWindow& window)
{
	Vector2f screenCentre = GameUpdater::getScreenCentre();
	bool game = false;
	Font font;
	font.loadFromFile("resources/font/PressStart2P-Regular.ttf");
	Text play("Continue", font, 50 * Camera::getZoomFactor());
	Text endGame("Exit", font, 50 * Camera::getZoomFactor());
	play.setFillColor(Color::Yellow);

	int pointer = 1;
	int max = 2;
	play.setPosition(screenCentre.x - play.getGlobalBounds().width / 2 , screenCentre.y - play.getGlobalBounds().height / 2 - 50 * Camera::getZoomFactor());
	endGame.setPosition(screenCentre.x - endGame.getGlobalBounds().width / 2 , screenCentre.y - endGame.getGlobalBounds().height / 2  + 50 * Camera::getZoomFactor());
	//string s;
	while (window.isOpen())
	{
		play.setFillColor(Color::White);
		endGame.setFillColor(Color::White);

		if (pointer > max) pointer = 1;
		if (pointer < 1) pointer = max;

		switch (pointer)
		{
		case(1):
			play.setFillColor(Color::Yellow);
			break;
		case(2):
			endGame.setFillColor(Color::Yellow);
			break;
		default:
			break;
		}

		Event event;
		while (window.pollEvent(event))
		{
			if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W)))
			{
				pointer++;
			}

			if ((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S)))
			{
				pointer--;
			}
			if (event.type == sf::Event::Closed)
				window.close();

			GameUpdater::getInstance().eventUpdate(event);
		}

		if (Keyboard::isKeyPressed(Keyboard::Enter))
		{
			switch (pointer)
			{
			case(1):
				game = true;
				break;
			case(2):
				window.close();
				break;
			default:
				break;
			}
		}
		if (game)
			break;

		window.clear();
		GameUpdater::getInstance().render(window);
		window.draw(play);
		window.draw(endGame);
		window.display();
	}

}

void Interface::interface(RenderWindow& window, int hitPoints, int coins)
{
	Vector2f screenCentre = GameUpdater::getScreenCentre();
	string str;
	str = "HP:" + to_string(hitPoints);
	Font font;
	font.loadFromFile("resources/font/PressStart2P-Regular.ttf");
	Text hp("", font, 30 * Camera::getZoomFactor());
	hp.setFillColor(Color::Red);
	hp.setString(str);
	hp.setPosition(screenCentre.x - 480 * Camera::getZoomFactor() + 10 * Camera::getZoomFactor(), screenCentre.y - 270 * Camera::getZoomFactor() + 20 * Camera::getZoomFactor());
	window.draw(hp);

	str = "C:" + to_string(coins);
	Text C("", font, 30 * Camera::getZoomFactor());
	C.setFillColor(Color::Yellow);
	C.setString(str);
	C.setPosition(screenCentre.x + 480 * Camera::getZoomFactor() - 10 * Camera::getZoomFactor() - C.getGlobalBounds().width, screenCentre.y - 270 * Camera::getZoomFactor() - 20 * Camera::getZoomFactor() + C.getGlobalBounds().height);
	window.draw(C);
}