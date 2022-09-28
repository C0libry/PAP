#include "Base.h"

Base::~Base() {};

Int64 Base::deltaTime;


Base::Base(const Objects& obj)
{
	sprite.setTexture(Loader::getTexture(obj));
	isEndOfAnimation = false;
}

Sprite& Base::getSprite()
{
	return sprite;
}

const Int64& Base::getDeltaTime()
{
	return deltaTime;
}

void Base::setDeltaTime(Int64 DeltaTime)
{
	deltaTime = DeltaTime;
}

float Base::distance(Vector2f point1, Vector2f point2)
{
	float distance;
	distance = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));
	return distance;
}

Vector2f Base::getCentrePosition()
{
	return Vector2f(sprite.getGlobalBounds().left + sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().top + sprite.getTextureRect().height / 2);
	//return sprite.getPosition();
}

const FloatRect Base::getHitBox()
{
	return hitBox;
}

FloatRect Base::getSpriteGlobalBounds()
{
	return sprite.getGlobalBounds();
}

//Temp function
void Base::drowRect(RenderWindow& window, FloatRect rect, Color c)
{
	RectangleShape Rect(Vector2f(rect.width, rect.height));
	//ectangleShape rectbot;
	Rect.setFillColor(c);
	//rectbot.setTextureRect(IntRect(bottom));
	Rect.setPosition(rect.left, rect.top);

	window.draw(Rect);
}

//Temp function
void Base::drowRays(RenderWindow& window)
{
	sf::RectangleShape line(sf::Vector2f(150, 10));
	line.rotate(45);
	line.setFillColor(Color::Red);
	window.draw(line);
}

/*
void Base::setHitBox(const FloatRect& hb)
{
	hitBox = hb;
}*/