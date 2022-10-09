#pragma once

#include "Include.h"
#include "Base.h"
#include "Utils.h"
#include "Animation.h"

enum  TileType
{
	SOLID,
	INVISIBLE,
	INVISIBLE_NOT_SOLID,
	COIN,
	DECOR,
	SPIKES,
	LEVER,
	DOOR,
	BACKGROUND
};

class Tile : public Base
{
protected:
	bool activated;
	TileType currentType;
	int number;

public:
	Tile(const Objects& obj, const TileType& type, const int Number, const IntRect& rect, const Vector2f& pos);
	bool getState();
	void setState(bool state);
	TileType getCurrentType();
	void render(RenderWindow& window) override;
	void update(Event& event) override;
	void eventUpdate(Event& event) override;
};