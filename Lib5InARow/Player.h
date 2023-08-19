#pragma once
#include "Piece.h"
#include "GameBoardModel.h"

class Player
{
private:
	Piece::Color m_color;
protected:
	GameBoardModel* m_board;
public:
	Player(Piece::Color color, GameBoardModel* board) : m_color {color}, m_board {board} {};
public:
	auto color() const { return m_color; }
public:
	virtual GameBoardModel::PutStatus putPiece() = 0;
};

