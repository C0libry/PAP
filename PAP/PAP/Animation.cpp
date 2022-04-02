#include "Animation.h"

Animator::~Animator() {};

void Animator::animation(const State nawAnimation, State& currentAnimation, Sprite& sprite, const bool invert, const int line, const int beg, const int end, float& currentFrame)
{
	if (!currentAnimation == nawAnimation)
	{
		currentFrame = beg;
		currentAnimation = nawAnimation;
	}

	int w = abs(sprite.getTextureRect().width);
	int h = abs(sprite.getTextureRect().height);
	currentFrame += 0.005 * Base::getDeltaTime();

	if (currentFrame < beg || currentFrame > end) currentFrame = beg;

	if (!invert) sprite.setTextureRect(sf::IntRect(w * int(currentFrame), h * line, w, h));
	else sprite.setTextureRect(sf::IntRect(w * int(currentFrame) + w, h * line, -w, h));
}

/*
void Animation::animation(const Objects& obj, const Anim& nawAnimation, Anim& currentAnimation, Sprite& sprite, const bool invert)
{
	switch (obj)
	{
	case player:
		anin(nawAnimation, Anim & currentAnimation, Sprite & sprite, const bool invert)
	default:
		break;
	}
}
void Animation::anim(const Anim& nawAnimation, Anim& currentAnimation, Sprite& sprite, const bool invert)
{
	switch (nawAnimation)
	{
	case 0:
		break;
		
	default:
		break;
	}
}*/