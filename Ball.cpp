#include "Ball.h"
#include <random>

Ball::Ball(float positionX, float positionY, int size, float speed)
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->size = size;
	this->speed = speed;

	SetDirection();
}

Ball::~Ball()
{
}

void Ball::Reset()
{
	SetDirection();
	oob = false;
}

void Ball::SetDirection()
{
	directionY = -1; // should always be going up to start with

	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(0, 1); // guaranteed unbiased

	auto random_integer = uni(rng);

	directionX = (random_integer * 2) - 1;
}

int Ball::GetPositionX()
{
	return positionX;
}

int Ball::GetPositionY()
{
	return positionY;
}

void Ball::SetPosition(int x, int y)
{
	positionX = x;
	positionY = y;
}

int Ball::GetSize()
{
	return this->size;
}

void Ball::Update(float fElapsedTime, int height, int width)
{
	float nextPositionX = positionX + ((speed * fElapsedTime) * directionX);
	float nextPositionY = positionY + ((speed * fElapsedTime) * directionY);

	// boundary checks
	if (nextPositionX <= 0)
	{
		nextPositionX = 0;
		directionX = -directionX;
	}
	else if (nextPositionX >= width)
	{
		nextPositionX = width;
		directionX = -directionX;
	}

	if (nextPositionY <= 0)
	{
		nextPositionY = 0;
		directionY = -directionY;
	}
	else if (nextPositionY >= height)
	{
		oob = true;
	}

	positionX = nextPositionX;
	positionY = nextPositionY;
}

bool Ball::CheckCollision(Bat bat)
{
	float batX = bat.GetPositionX();
	float batY = bat.GetPositionY();

	if (positionY >= batY && positionX >= batX && positionX <= batX + bat.GetSizeX()) {
		positionY = batY;
		directionY = -directionY;
		directionX = bat.GetDirectionX();
		return true;
	}

	return false;
}

bool Ball::CheckCollision(Brick brick)
{
	int brickX = brick.GetPositionX();
	int brickY = brick.GetPositionY();

	if (positionX >= brickX && positionX <= (brickX + brick.GetSizeX()) && positionY >= brickY && positionY <= (brickY + brick.GetSizeY()))
	{
		directionY = -directionY;
		return true;
	}

	return false;
}

bool Ball::IsOOB()
{
	return oob;
}