#include "Game.h"
#include <thread>

Game::Game()
	: ball(100, 100, 5, 250.0f), bat(100, 100, 150, 10)
{
	sAppName = "PGE Breakout Game";
}

Game::~Game()
{
}

bool Game::OnUserCreate()
{
	PlaceElements();

	GenerateBricks();

	return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	Clear(olc::BLACK);

	if (showMenu)
	{
		DrawString(100, 200, "OLC CodeJam 2019\n\nBreakOut", olc::DARK_RED, 3);
		DrawString(100, 300, "By SaladinAkara", olc::GREEN, 2);
		DrawString(100, 500, "Click the screen to start", olc::WHITE, 2);

		DrawString(100, ScreenHeight() - 50, "Powered by olcPixelGameEngine from onelonecoder.com");

		if (GetMouse(0).bPressed)
		{
			showMenu = false;
		}

		return true;
	}

	ball.Update(fElapsedTime, ScreenHeight(), ScreenWidth());

	if (ball.IsOOB())
	{
		// show the win screen
		DrawString(100, 100, "Sorry, you lost!", olc::WHITE, 4);
		DrawString(100, 200, "Click to reset.", olc::WHITE, 2);

		if (GetMouse(0).bPressed)
		{
			Reset();
		}

		return true;
	}


	bat.SetPosition(GetMouseX());
	if (ball.CheckCollision(bat))
	{
		combo = 0;
	}

	bool hasBricks = false;

	for (auto &brick : bricks)
	{
		if (brick.ShouldRender()) // only check the bricks that are on screen
		{
			hasBricks = true;
			if (ball.CheckCollision(brick))
			{
				brick.SetIsDestroyed(true);
				score += scorePerBrick + comboBonus * combo;
				combo++;
			}
		}
	}

	if (!hasBricks)
	{
		// show the win screen
		DrawString(100, 100, "You win!\n\nWell done!", olc::WHITE, 4);
		DrawString(100, 225, "Score: " + std::to_string(score), olc::WHITE, 2);
		DrawString(100, 500, "Click to reset.", olc::WHITE, 2);

		if (GetMouse(0).bPressed)
		{
			Reset();
		}

		return true;
	}

	DrawString(10, 10, "Score: " + std::to_string(score));

	// draw ball
	FillCircle(ball.GetPositionX(), ball.GetPositionY(), ball.GetSize());
	// draw bat
	FillRect(bat.GetPositionX(), bat.GetPositionY(), bat.GetSizeX(), bat.GetSizeY());
	// draw bricks
	for (auto &brick : bricks)
	{
		if (brick.ShouldRender())
		{
			FillRect(brick.GetPositionX(), brick.GetPositionY(), brick.GetSizeX(), brick.GetSizeY(), olc::Pixel(brick.GetR(), brick.GetG(), brick.GetB()));
		}
	}

	return true;
}

void Game::GenerateBricks()
{
	int brickRows = 15;
	int brickCols = 8;
	int brickHeight = 30;
	int brickWidth = 75;
	int brickStartX = 80;
	int brickStartY = 40;

	for (int i = 0; i < brickRows; i++)
	{
		for (int j = 0; j < brickCols; j++)
		{
			bricks.push_back(Brick(brickStartX + (j * brickWidth), brickStartY + (i * brickHeight), brickWidth, brickHeight, rand() % 255, rand() % 255, rand() % 255));
		}
	}
}

void Game::PlaceElements()
{
	// position elements
	ball.SetPosition(ScreenWidth() / 2, ScreenHeight() - 20);
	bat.SetPosition(ScreenWidth() / 2, ScreenHeight() - 10);
}

void Game::Reset()
{
	bricks.clear();
	PlaceElements();
	ball.Reset();
	GenerateBricks();

	showMenu = true;
	score = 0;
}