#pragma once

#include "olcPixelGameEngine.h"
#include "Ball.h"
#include "Bat.h"
#include "Brick.h"
#include <vector>

class Game : public olc::PixelGameEngine
{
public:
	Game();
	~Game();

public:
	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

protected:
	Ball ball;
	Bat bat;
	std::vector<Brick> bricks;
	int score = 0;
	int scorePerBrick = 100;
	int comboBonus = 10;
	int combo = 0;
	bool showMenu = true;

	void GenerateBricks();
	void PlaceElements();
	void Reset();
};

