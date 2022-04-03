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
			//if (onGround) newState = MOVE;
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
			//if (onGround) newState = MOVE;
		}
	}

	if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
	{
		//sprite.move(0, -0.1f * deltaTime);
	}

	if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S))))
	{
		//sprite.move(0, 0.1f * deltaTime);
	}

	if (event.type == Event::KeyReleased)
	{
		//if (event.key.code == Keyboard::Space)
		//if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
		if ((event.key.code == Keyboard::Up) || (event.key.code == Keyboard::W) || (event.key.code == Keyboard::Space))
		{
			spacePressed = false;
		}
	}

	//if (Keyboard::isKeyPressed(Keyboard::Space))
	//if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W))))
	if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W)) || (Keyboard::isKeyPressed(Keyboard::Space)))
	{
		//dy -= 0.01f;
		if (!spacePressed && onGround)
		{
			dy = -0.11f;
			spacePressed = true;
			onGround = false;
		}
	}

	if (isCeilingCollide)
		dy = 0;

	if (dx == 0)
		newState = STAND;
}

Player::Player(const Objects& obj, const IntRect& rect, const Vector2f& pos) : Entity(obj, rect, pos)
{
	hp = 100;
	strength = 10;
	lookLeft = false;
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

void Player::render(RenderWindow& window)
{
	drowBorders(window);
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
	control(event);
	//enemyCollision();
	fall();
	playerAnimator();
	dx = 0;
}

void Player::eventUpdate(Event& event)
{
	/*
	if (event.type == Event::KeyReleased)
	{
		if (event.key.code == Keyboard::Space)
		{
			spacePressed = false;
		}
	}*/
}
/*
void Player::playerState()
{
	switch (this->currentState)
	{
	case State::STAND:
		ifStand();
		break;
	case State::MOVE:
		ifMove();
		break;
	case State::JUMP:
		ifJump();
		break;
	case State::ATTACK:
		ifAttack();
		break;
	case State::CAST_SPELL:
		ifCastSpell();
		break;
	case State::UP_LADDER:
		ifUpLadder();
		break;
	case State::DOWN_LADDER:
		ifDownLadder();
		break;
	case State::DEATH:
		break;
	default:
		break;
	}
}

void ifStand()
{
}

void ifMove()
{}

void ifJump()
{}

void ifAttack()
{}

void ifCastSpell()
{}

void ifUpLadder()
{}

void ifDownLadder()
{}*/
