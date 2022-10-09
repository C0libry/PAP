#pragma once

#include "Include.h"
#include "Entity.h"
#include "Animation.h"
#include "Map.h"

class Player : public Entity
{
protected:
	bool spacePressed;
	int coins;
	void control(Event& event);
	void attack() override;
	void playerAnimator();
	void updatePlayerAttackZone();
public:
	Player(const Objects& obj, const IntRect& rect, const Vector2f& pos);
	void render(RenderWindow& window) override;
	void update(Event& event) override;
	void eventUpdate(Event& event) override;
	void isCoinsCollided();
	bool isLife();
	int getCoins();
};
