#pragma once

#include "Include.h"

static const int SIZE = 3;
static Texture textureList[SIZE];

//Класс, который загружает текстуры
class Loader {
private:
	virtual ~Loader() = 0;
public:

	//Функция начала загрузки текстур
	static bool startLoad();

	//Функция которая возвращает текстуру по имени объекта
	static Texture& getTexture(const Objects& obj);
};