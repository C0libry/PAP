#include "HellHound.h"

Sprite idle;
Sprite jump;
Sprite run;
Sprite walk;

void HellHound::control(Event& event)
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
		//sprite.setPosition(run.getPosition());
	}
	if (hp <= 0)
		newState = DEATH;
}

void HellHound::hellHoundAnimator()
{
	switch (newState)
	{
	case State::STAND:
		Animator::animation(newState, currentState, this->sprite, !lookLeft, 0, 0, 5, currentFrame);
		isEndOfAnimation = false;
		break;
	case State::MOVE:
		Animator::animation(newState, currentState, walk, !lookLeft, 0, 0, 11, currentFrame);
		break;
	case State::JUMP:
		Animator::animation(newState, currentState, jump, !lookLeft, 0, 0, 5, currentFrame);
		break;
	case State::ATTACK:
		//if (!isEndOfAnimation) isEndOfAnimation = Animator::animation(newState, currentState, this->sprite, !lookLeft, 1, 1, 6, currentFrame);
		Animator::animation(newState, currentState, run, !lookLeft, 0, 0, 4, currentFrame);
		break;
	case State::DEATH:
		life = false;
		break;
	default:
		break;
	}
}

HellHound::HellHound(const Objects& obj, const IntRect& rect, const Vector2f& pos, Player& p) : Enemy(obj, rect, pos, p)
{
	hp = 30;
	strength = 20;
	jump.setTexture(Loader::getTexture(HELL_HOUND_JUMP));
	run.setTexture(Loader::getTexture(HELL_HOUND_RUN));
	walk.setTexture(Loader::getTexture(HELL_HOUND_WALK));

	jump.setTextureRect(IntRect(0, 0, 65, 48));
	run.setTextureRect(IntRect(0, 0, 67, 32));
	walk.setTextureRect(IntRect(0, 0, 64, 32));

	jump.setPosition(pos);
	run.setPosition(pos);
	walk.setPosition(pos);
}

void HellHound::render(RenderWindow& window)
{
	switch (currentState)
	{
	case State::STAND:
		window.draw(this->sprite);
		break;
	case State::MOVE:
		window.draw(walk);
		break;
	case State::JUMP:
		window.draw(jump);
		break;
	case State::ATTACK:
		window.draw(run);
		break;
	default:
		break;
	}
}
void HellHound::update(Event& event)
{
	hitBox = FloatRect(sprite.getGlobalBounds());
	hitBox.top += 11;
	hitBox.height -= 11;
	hitBox.left += 13;
	hitBox.width -= (13 + 13);
	mapCollision();
	control(event);
	fall();
	attackZone = hitBox;
	if (onGround)
		sprite.move(0, -0.11 * deltaTime);
	jump.setPosition(sprite.getPosition());
	run.setPosition(sprite.getPosition());
	walk.setPosition(sprite.getPosition());
	hellHoundAnimator();
	attack();
	dx = 0;
}

void HellHound::attack()
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

void HellHound::eventUpdate(Event& event)
{}

void HellHound::setTimer(Int64 timer)
{
	this->timer = timer;
}
Int64 HellHound::getTimer()
{
	return this->timer;
}