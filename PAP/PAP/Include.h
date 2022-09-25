#pragma once

#ifndef INCLUDE_H
#define INCLUDE_H

#include "imgui/imgui.h"
#include "imgui/imconfig-SFML.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <math.h>
#include <thread>
//#include <chrono>

#include "tinyxml2.h"
//#include "level.h"

using namespace std;
using namespace sf;

//Перечисление - содержащие все названия анимаций
enum State
{
	STAND,
	MOVE,
	JUMP,
	ATTACK,
	CAST_SPELL,
	UP_LADDER,
	DOWN_LADDER,
	DEATH
};

//enum ObjectTeg

//Перечисление - содержащие все имена объекта
enum Objects
{
	PLAYER,
	ASSETS,
	SLIME,
	HELL_HOUND_IDLE,
	HELL_HOUND_JUMP,
	HELL_HOUND_RUN,
	HELL_HOUND_WALK
};

//Глобальные статические константы
//static const String TILE_BOX = "resources/images/tile.png";
static const String TILE_ASSETS = "resources/images/Assets.png";
static const String HERO_NAME = "resources/images/adventurer-v1.5-Sheet.png";
static const String SLIME_NAME = "resources/images/slime-Sheet.png";
static const String HELL_HOUND_IDLE_NAME = "resources/images/hell-hound-idle.png";
static const String HELL_HOUND_JUMP_NAME = "resources/images/hell-hound-jump.png";
static const String HELL_HOUND_RUN_NAME = "resources/images/hell-hound-run.png";
static const String HELL_HOUND_WALK_NAME = "resources/images/hell-hound-walk.png";

static const float GRAVITY = 0.0003f;

#endif