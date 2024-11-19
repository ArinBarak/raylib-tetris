#include <assert.h>
#include "Game.h"
#include "raylibcpp.h"
#include "Settings.h"

Game::Game(int width, int height, int fps, std::string title)
	:board(settings::boardPosition, settings::boardWidthHeight, settings::cellSize, settings::padding),
			tetromino(board) {
	assert(!GetWindowHandle());
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept
{
	assert(GetWindowHandle());
	CloseWindow();
}

bool Game::GameShouldContinue() const
{
	return WindowShouldClose();
}

void Game::Tick()
{
	BeginDrawing();
	Update();
	Draw();
	EndDrawing();
}

void Game::Update() {
	if (IsKeyPressed(KEY_UP)) {
		tetromino.RotateClockwise();
	}
	if (IsKeyPressed(KEY_DOWN)) {
		tetromino.RotateCounterClockwise();
	}
	
	if (IsKeyPressed(KEY_RIGHT)) {
		tetromino.MoveDown();
	}

}

void Game::Draw() {
	ClearBackground(BLACK);
	board.Draw();
	tetromino.Draw();
}
