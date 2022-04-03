#pragma once

#include "Include.h"
#include "Utils.h"

class Base
{
protected:
	static float deltaTime;
	Sprite sprite;
	FloatRect hitBox;
	bool isEndOfAnimation;
	//Objects type;
	Base(const Objects& obj);
	virtual ~Base() = 0;
public:
	/*
	Vector2f getPosition()
	{
		return sprite.getPosition();
	}
	void setPosition(const Vector2f& pos)
	{
		sprite.setPosition(pos);
	}

	void move(float x, float y)
	{
		sprite.move(x, y);
	}
	*/
	//static float& getDeltaTime();
	//static void setDeltaTime(float DeltaTime);

	Sprite& getSprite();
	static float& getDeltaTime();
	static void setDeltaTime(float DeltaTime);
	static float distance(Vector2f point1, Vector2f point2);
	Vector2f getPosition();
	const FloatRect getHitBox();
	//void setHitBox(const FloatRect& hb);

	virtual void render(RenderWindow& window) = 0;
	virtual void update(Event& event) = 0;
	virtual void eventUpdate(Event& event) = 0;
};