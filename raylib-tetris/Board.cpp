#include "Board.h"
#include <assert.h>

Board::Cell::Cell(): bExists(false), c(RAYWHITE) {}

void Board::Cell::SetColor(Color c_in)
{
	c = c_in;
	bExists = true;
}

void Board::Cell::Remove()
{
	bExists = false;
}

bool Board::Cell::Exists() const
{
	return bExists;
}

Color Board::Cell::GetColor() const
{
	return c;
}

Board::Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellsize_in, int padding)
: screenPos(screenPos), width(widthHeight.GetX()), height(widthHeight.GetY()),
cellSize(cellsize_in), padding(padding)
{
	assert(width > 0 && height > 0);
	assert(cellSize > 0);
	cells.resize(width * height);
}

void Board::SetCell(Vec2<int> pos, Color c)
{
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < width && pos.GetY() < height);
	cells[pos.GetY() * width + pos.GetX()].SetColor(c);
}

void Board::DrawCell(Vec2<int> pos) const
{
	Color color = cells[pos.GetY() * width + pos.GetX()].GetColor();
	DrawCell(pos, color);
}

void Board::DrawCell(Vec2<int> pos, Color color) const
{
	assert(pos.GetX() >= 0 && pos.GetX() < width && pos.GetY() >= 0 && pos.GetY() < height);
	Vec2<int> topLeft = screenPos + padding + (pos * cellSize);
	raycpp::DrawRectangle(topLeft, Vec2<int>{ cellSize,cellSize } - padding, color);
}

void Board::DrawBorder() const
{
	raycpp::DrawRectangleLinesEx((screenPos - (cellSize / 2)),
		Vec2<int>{ width * cellSize,height * cellSize } + cellSize,
		cellSize / 2,
		WHITE);
}

void Board::Draw() const
{
	for (int iY = 0; iY < height; ++iY) {
		for (int iX = 0; iX < width; ++iX) {
			if (CellExists({ iX, iY })) {
				DrawCell({ iX, iY });
			}
		}
	}
	DrawBorder();
}

bool Board::CellExists(Vec2<int> pos) const
{
	return cells[pos.GetY() * width + pos.GetX()].Exists();
}

int Board::GetWidth() const
{
	return width;
}

int Board::GetHeight() const
{
	return height;
}



