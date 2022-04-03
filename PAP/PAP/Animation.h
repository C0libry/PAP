#pragma once

#include "Include.h"
#include "Base.h"

class Animator
{
private:
	virtual ~Animator() = 0;
public:
	static bool animation(const State nawAnimation, State& currentAnimation, Sprite& sprite, const bool invert, const int line, const int beg, const int end, float& currentFrame);
};