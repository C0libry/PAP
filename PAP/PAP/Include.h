#pragma once

#ifndef INCLUDE_H
#define INCLUDE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>

#include "tinyxml2.h"
//#include "level.h"

using namespace std;
using namespace sf;

//������������ - ���������� ��� �������� ��������
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

//enum Objectteg

//������������ - ���������� ��� ����� �������
enum Objects
{
	PLAYER,
	BOX,
	SLIME
};

//���������� ����������� ���������
static const String TILE_BOX = "resources/images/tile.png";
static const String HERO_NAME = "resources/images/adventurer-v1.5-Sheet.png";
static const String SLIME_NAME = "resources/images/slime-Sheet.png";

static const float GRAVITY = 0.0003f;

#endif