#include "Animation.h"

Animator::~Animator() {};

bool Animator::animation(const State nawAnimation, State& currentAnimation, Sprite& sprite, const bool invert, const int line, const int beg, const int end, float& currentFrame)
{
	bool isEndOfAnimation;
	if (!currentAnimation == nawAnimation)
	{
		currentFrame = beg;
		currentAnimation = nawAnimation;
	}

	int w = abs(sprite.getTextureRect().width);
	int h = abs(sprite.getTextureRect().height);
	currentFrame += 0.005 * Base::getDeltaTime();

	if (currentFrame < beg || currentFrame > end)
	{
		currentFrame = beg;
		isEndOfAnimation = true;
	} else isEndOfAnimation = false;

	if (!invert) sprite.setTextureRect(sf::IntRect(w * int(currentFrame), h * line, w, h));
	else sprite.setTextureRect(sf::IntRect(w * int(currentFrame) + w, h * line, -w, h));

	return isEndOfAnimation;
}