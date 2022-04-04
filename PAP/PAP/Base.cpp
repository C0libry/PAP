#include "Base.h"

Base::~Base() {};

float Base::deltaTime;


Base::Base(const Objects& obj)
{
	sprite.setTexture(Loader::getTexture(obj));
	isEndOfAnimation = false;
}

Sprite& Base::getSprite()
{
	return sprite;
}

float& Base::getDeltaTime()
{
	return deltaTime;
}

void Base::setDeltaTime(float DeltaTime)
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

/*
void Base::setHitBox(const FloatRect& hb)
{
	hitBox = hb;
}*/