#include "Interface.h"

void Interface::mainMenu(RenderWindow& window)
{
	/*
	Font font;
	font.loadFromFile("resources/font/PressStart2P-Regular.ttf");
	Text text("Text", font, 20);
	text.setFillColor(Color::Black);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	sleep(seconds(10));
	*/
	bool game = false;
	Font font;
	font.loadFromFile("resources/font/PressStart2P-Regular.ttf");
	Text play("Play", font, 100);
	Text endGame("Exit", font, 100);
	play.setFillColor(Color::Yellow);

	int pointer = 1;
	int max = 2;


	play.setPosition(960 / 2 - play.getGlobalBounds().width / 2, 540 / 2 - play.getGlobalBounds().height / 2 - 100);
	endGame.setPosition(960 / 2 - endGame.getGlobalBounds().width / 2, 540 / 2 - endGame.getGlobalBounds().height / 2 + 100);
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
			if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
			{
				pointer++;
			}

			if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
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
	Text play("Continue", font, 100);
	Text endGame("Exit", font, 100);
	play.setFillColor(Color::Yellow);

	int pointer = 1;
	int max = 2;
	play.setPosition(screenCentre.x - play.getGlobalBounds().width / 2, screenCentre.y - play.getGlobalBounds().height / 2 - 100);
	endGame.setPosition(screenCentre.x - endGame.getGlobalBounds().width / 2, screenCentre.y - endGame.getGlobalBounds().height / 2 + 100);
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
			if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
			{
				pointer++;
			}

			if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
			{
				pointer--;
			}
			if (event.type == sf::Event::Closed)
				window.close();

			GameUpdater::getInstance().eventUpdate(event);
		}
		window.clear();
		window.draw(play);
		window.draw(endGame);
		window.display();

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
		//GameUpdater::getInstance().render(window);
		window.draw(play);
		window.draw(endGame);
		window.display();
	}

}