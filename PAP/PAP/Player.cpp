#include "Player.h"

void Player::control(Event& event)
{
	if ((Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)) && !isLeftSideCollide)
	{
		if (!(Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)))
		{
			isRightSideCollide = false;
			lookLeft = true;
			dx = -0.15f;
			sprite.move(dx * deltaTime, 0);
			newState = MOVE;
		}
	}

	if ((Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) && !isRightSideCollide)
	{
		if (!(Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)))
		{
			isLeftSideCollide = false;
			lookLeft = false;
			dx = 0.15f;
			sprite.move(dx * deltaTime, 0);
			newState = MOVE;
		}
	}
	if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W)) || (Keyboard::isKeyPressed(Keyboard::Space)))
	{
		if (!spacePressed && onGround)
		{
			dy = -0.11f;
			onGround = false;
		}
	}

	if (isCeilingCollide)
		dy = 0;

	if (dx == 0)
		newState = STAND;

	if (Keyboard::isKeyPressed(Keyboard::LShift))
	{
		isAttack = true;
		newState = ATTACK;
	}
	else
	{
		isAttack = false;
	}

	if (hp <= 0)
		newState = DEATH;
}

Player::Player(const Objects& obj, const IntRect& rect, const Vector2f& pos) : Entity(obj, rect, pos)
{
	hp = 100;
	strength = 10;
	lookLeft = false;
	isAttack = false;
	spacePressed = false;
}

void Player::playerAnimator()
{
	switch (newState)
	{
	case State::STAND:
		Animator::animation(newState, currentState, this->sprite, lookLeft, 0, 0, 3, currentFrame);
		break;
	case State::MOVE:
		Animator::animation(newState, currentState, this->sprite, lookLeft, 1, 1, 6, currentFrame);
		break;
	case State::JUMP:
		Animator::animation(newState, currentState, this->sprite, lookLeft, 1, 1, 6, currentFrame);
		break;
	case State::ATTACK:
		Animator::animation(newState, currentState, this->sprite, lookLeft, 7, 0, 3, currentFrame);
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

void Player::attack()
{}

void Player::updatePlayerAttackZone()
{
	if (lookLeft)
	{
		attackZone.left = hitBox.left - hitBox.width;
		attackZone.top = hitBox.top;
		attackZone.width = hitBox.width * 2;
		attackZone.height = hitBox.height;
	}
	else
	{
		attackZone.left = hitBox.left;
		attackZone.top = hitBox.top;
		attackZone.width = hitBox.width * 2;
		attackZone.height = hitBox.height;
	}
}


void Player::render(RenderWindow& window)
{
	window.draw(this->sprite);
}

void Player::update(Event& event)
{
	hitBox = FloatRect(sprite.getGlobalBounds());
	hitBox.top += 7;
	hitBox.height -= 9;
	hitBox.left += 16;
	hitBox.width -= (18 + 16);
	mapCollision();
	updatePlayerAttackZone();
	control(event);
	fall();
	playerAnimator();
	isCoinsCollided();
	dx = 0;
}

void Player::eventUpdate(Event& event) {}

void Player::isCoinsCollided()
{
	vector<Tile> map = Map::getMap();

	for (int i = 0; i < map.size(); i++)
	{
		if (hitBox.intersects(map[i].getHitBox()) && map[i].getCurrentType() == COIN)
		{
			coins++;
			Map::getMap().erase(Map::getMap().begin() + i);
		}
	}
}

bool Player::isLife()
{
	return life;
}

int Player::getCoins()
{
	return coins;
}
