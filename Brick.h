#pragma once
#include "olcPixelGameEngine.h"

class Brick
{
public:
	Brick(int positionX, int positionY, int sizeX, int sizeY, int r, int g, int b);
	~Brick();

	int GetPositionX();
	int GetPositionY();
	int GetSizeX();
	int GetSizeY();
	int GetR();
	int GetG();
	int GetB();

	bool ShouldRender();

	void SetIsDestroyed(bool destroy);

private:
	int positionX, positionY, sizeX, sizeY, r, b, g;
	bool isDestroyed = false;
	olc::Pixel pixel;
};

