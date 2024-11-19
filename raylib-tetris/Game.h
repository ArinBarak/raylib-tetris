#pragma once
#include <string>
#include "Board.h"
#include "Tetrominoes.h"

class Game {
	void Update();
	void Draw();

	Board board;
	Jay tetromino;
public:
	Game(int width, int height, int fps, std::string title);
	Game(const Game& other)=delete;
	Game& operator=(const Game& other) = delete;
	~Game() noexcept;
	bool GameShouldContinue() const;
	void Tick();
};