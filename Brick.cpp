#include "Brick.h"

Brick::Brick(int positionX, int positionY, int sizeX, int sizeY, int r, int b, int g)
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->r = r;
	this->b = b;
	this->g = g;
}

Brick::~Brick()
{
}

int Brick::GetPositionX()
{
	return positionX;
}

int Brick::GetPositionY()
{
	return positionY;
}

int Brick::GetSizeX()
{
	return sizeX;
}

int Brick::GetSizeY()
{
	return sizeY;
}

bool Brick::ShouldRender()
{
	return !isDestroyed;
}

void Brick::SetIsDestroyed(bool destroy)
{
	isDestroyed = destroy;
}

int Brick::GetR()
{
	return r;
}

int Brick::GetG()
{
	return g;
}

int Brick::GetB()
{
	return b;
}