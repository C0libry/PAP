#pragma once

#include "Include.h"
#include "Entity.h"
#include "Animation.h"
#include "Map.h"

class Player : public Entity
{
protected:
	bool spacePressed;
	void control(Event& event);
	void playerAnimator();
	void enemyCollision();
	//void playerState();
public:
	Player(const Objects& obj, const IntRect& rect, const Vector2f& pos);
	void render(RenderWindow& window) override;
	void update(Event& event) override;
	void eventUpdate(Event& event) override;
	bool isLife();
};

/*
class stateTree
{
public:
	void chooseTree(Objects& obj, vector<bool>& tags);
	void playerStateTree(vector<bool>& tags);
};

void stateTree::chooseTree(Objects& obj, vector<bool>& tags)
{
}
void stateTree::playerStateTree(vector<bool>& tags)
{
	if (1) {}
}
*/
