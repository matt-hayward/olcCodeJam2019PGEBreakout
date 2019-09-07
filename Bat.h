#pragma once

class Bat
{
public:
	Bat(float positionX, float positionY, int sizeX, int sizeY);
	~Bat();

public:
	void SetPosition(float positionX, float positionY);
	void SetPosition(float positionX);
	float GetPositionX();
	float GetPositionY();
	int GetSizeX();
	int GetSizeY();
	int GetDirectionX();

protected:
	float positionX, positionY;
	int sizeX, sizeY;
	int directionX = 0;
};

