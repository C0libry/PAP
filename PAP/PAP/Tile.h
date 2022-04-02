#pragma once

#include "Include.h"
#include "Base.h"
#include "Utils.h"

class Tile : public Base
{
protected:
	bool solid;
public:
	Tile(const Objects& obj, const IntRect& rect, const Vector2f& pos);
	bool getSolid();
	void render(RenderWindow& window) override;
	void update(Event& event) override;
	void eventUpdate(Event& event) override;
};