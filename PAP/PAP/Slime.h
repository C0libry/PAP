#pragma once

#include "Include.h"
#include "Base.h"
#include "Enemy.h"
#include "Player.h"
#include "GameUpdater.h"

class Slime: public Enemy
{
protected:
	Int64 timer = 0;
	void control(Event& event);
	void attack() override;
	void slimeAnimator();
public:
	Slime(const Objects& obj, const IntRect& rect, const Vector2f& pos, Player& p);
	void render(RenderWindow& window) override;
	void update(Event& event) override;
	void eventUpdate(Event& event) override;
	void setTimer(Int64 timer);
	Int64 getTimer();
};
