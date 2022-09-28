#pragma once

#include "Include.h"
#include "GameUpdater.h"
#include "Camera.h"

class Interface
{
public:
	static void mainMenu(RenderWindow& window);
	static void paus(RenderWindow& window);
	static void interface(RenderWindow& window, int hitPoints, int coins);
};