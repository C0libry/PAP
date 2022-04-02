#pragma once

#include "Include.h"
#include "Entity.h"
#include "Player.h"

class Enemy: public Entity
{
protected:
	Enemy(const Objects& obj, const IntRect& rect, const Vector2f& pos);
public:
	virtual void render(RenderWindow& window) = 0;
	virtual void update(Event& event) = 0;
	virtual void eventUpdate(Event& event) = 0;
};