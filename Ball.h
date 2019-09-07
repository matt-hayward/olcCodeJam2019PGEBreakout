#pragma once
#include "Bat.h"
#include "Brick.h"

class Ball
{
public:
	Ball(float positionX, float positionY, int size, float speed);
	~Ball();

	int GetPositionX();
	int GetPositionY();
	int GetSize();

	void Update(float fElapsedTime, int height, int width);
	void SetPosition(int x, int y);
	bool CheckCollision(Bat bat);
	void Reset();
	void SetDirection();

	bool CheckCollision(Brick brick);
	bool IsOOB();

protected:
	float positionX, positionY;
	int size, speed, directionX, directionY;
	bool oob = false;
};

