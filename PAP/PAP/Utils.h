#pragma once

#include "Include.h"

static const int SIZE = 3;
static Texture textureList[SIZE];

//�����, ������� ��������� ��������
class Loader {
private:
	virtual ~Loader() = 0;
public:

	//������� ������ �������� �������
	static bool startLoad();

	//������� ������� ���������� �������� �� ����� �������
	static Texture& getTexture(const Objects& obj);
};