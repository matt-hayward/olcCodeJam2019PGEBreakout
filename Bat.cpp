#include "Bat.h"

Bat::Bat(float positionX, float positionY, int sizeX, int sizeY)
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}


Bat::~Bat()
{
}

void Bat::SetPosition(float positionX, float positionY)
{
	this->positionX = positionX;
	this->positionY = positionY;
}

void Bat::SetPosition(float positionX)
{
	float oldPosition = this->positionX;
	this->positionX = positionX - (sizeX / 2);
	if (this->positionX > oldPosition)
	{
		directionX = 1;
	}
	else
	{
		directionX = -1;
	}
}

float Bat::GetPositionX()
{
	return this->positionX;
}

float Bat::GetPositionY()
{
	return this->positionY;
}

int Bat::GetSizeX()
{
	return this->sizeX;
}

int Bat::GetSizeY()
{
	return this->sizeY;
}

int Bat::GetDirectionX()
{
	return directionX;
}