#pragma once

#include "Include.h"
#include "Player.h"

class Camera
{
public:
	static View& load();
	static void move(View& camera, const Vector2f& pos);
	static void render(View& camera, RenderWindow& window);
	static void scrolle(View& camera, Event& event);
	static float getZoomFactor();
};