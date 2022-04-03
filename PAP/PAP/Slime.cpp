#include "Slime.h"

void Slime::control(Event& event)
{
	//currentState = STAND;
	newState = STAND;
	float Distance = distance(sprite.getPosition(), player->getPosition());
	if (Distance < 400 && Distance > 30)
	{
		if (player->getPosition().x < sprite.getPosition().x)
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
	else if (Distance < 30)
	{
		attack();
	}
}

void Slime::attack()
{
	newState = ATTACK;
	isAttack = true;
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
	case State::JUMP:
		break;
	case State::ATTACK:
		//if (!isEndOfAnimation) isEndOfAnimation = Animator::animation(newState, currentState, this->sprite, !lookLeft, 1, 1, 6, currentFrame);
		Animator::animation(newState, currentState, this->sprite, !lookLeft, 1, 1, 6, currentFrame);
		break;
	case State::CAST_SPELL:
		break;
	case State::UP_LADDER:
		break;
	case State::DOWN_LADDER:
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
	strength = 3;
}

void Slime::render(RenderWindow& window)
{
	//drowRect(window, hitBox, Color::Blue);
	//drowRect(window, attackHitBox, Color::Blue);
	drowRect(window, borderBottom, Color::Magenta);
	drowRect(window, borderRight, Color::Yellow);
	drowRect(window, borderLeft, Color::Cyan);
	drowRect(window, borderTop, Color::Red);

	window.draw(this->sprite);
}
void Slime::update(Event& event)
{
	hitBox = FloatRect(sprite.getGlobalBounds());
	hitBox.top += 13;
	hitBox.height -= (13 + 2);
	hitBox.left += 3;
	hitBox.width -= (3 + 3);
	attackHitBox = hitBox;
	mapCollision();
	control(event);
	fall();
	slimeAnimator();
	dx = 0;
}
void Slime::eventUpdate(Event& event)
{}