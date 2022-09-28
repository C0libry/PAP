#include "Slime.h"

void Slime::control(Event& event)
{
	//currentState = STAND;
	newState = STAND;
	float Distance = distance(getCentrePosition(), player->getCentrePosition());
	if (Distance < 400 && Distance > 10)
	{
		if (player->getCentrePosition().x < sprite.getPosition().x)
		{
			if (!isLeftSideCollide)
			{
				//cout << distance(sprite.getPosition(), player->getPosition());
				isRightSideCollide = false;
				lookLeft = true;
				dx = -0.05f;
				sprite.move(dx * deltaTime, 0);
				newState = MOVE;
				//if (onGround) newState = MOVE;
			}
		}
		else
		{
			if (!isRightSideCollide)
			{
				isLeftSideCollide = false;
				lookLeft = false;
				dx = 0.05f;
				sprite.move(dx * deltaTime, 0);
				newState = MOVE;
			}
		}
	}
	else if (Distance < 10)
	{
		newState = ATTACK;
		isAttack = true;
	}
	if (hp <= 0)
		newState = DEATH;
}

void Slime::slimeAnimator()
{
	switch (newState)
	{
	case State::STAND:
		Animator::animation(newState, currentState, this->sprite, !lookLeft, 0, 0, 4, currentFrame);
		isEndOfAnimation = false;
		break;
	case State::MOVE:
		Animator::animation(newState, currentState, this->sprite, !lookLeft, 0, 4, 8, currentFrame);
		break;
	case State::ATTACK:
		//if (!isEndOfAnimation) isEndOfAnimation = Animator::animation(newState, currentState, this->sprite, !lookLeft, 1, 1, 6, currentFrame);
		Animator::animation(newState, currentState, this->sprite, !lookLeft, 1, 1, 6, currentFrame);
		break;
	case State::DEATH:
		life = false;
		break;
	default:
		break;
	}
}

Slime::Slime(const Objects& obj, const IntRect& rect, const Vector2f& pos, Player& p) : Enemy(obj, rect, pos, p)
{
	hp = 20;
	strength = 10;
}

void Slime::render(RenderWindow& window)
{
	window.draw(this->sprite);
}
void Slime::update(Event& event)
{
	hitBox = FloatRect(sprite.getGlobalBounds());
	hitBox.top += 13;
	hitBox.height -= (13 + 2);
	hitBox.left += 3;
	hitBox.width -= (3 + 3);
	attackZone = hitBox;
	mapCollision();
	control(event);
	fall();
	slimeAnimator();
	attack();
	dx = 0;
}

void Slime::attack()
{
	int delay = 1 * 1000;
	Int64 GameTime = GameUpdater::getGameTime();
	if (player->getHitBox().intersects(getAttackHitBox()))
	{
		if (getTimer() + delay < GameTime)
		{
			player->setHP(player->getHP() - strength);
			setTimer(GameTime);
		}
	}
	if (player->getIsAttack())
	{
		if (player->getAttackHitBox().intersects(getHitBox()))
		{
			setHP(getHP() - player->gerStrength());
		}
	}
}

void Slime::eventUpdate(Event& event)
{}

void Slime::setTimer(Int64 timer)
{
	this->timer = timer;
}
Int64 Slime::getTimer()
{
	return this->timer;
}