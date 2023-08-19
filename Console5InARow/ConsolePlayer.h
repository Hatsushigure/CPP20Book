#pragma once
#include "Player.h"

class ConsolePlayer : public Player
{
public:
	ConsolePlayer(Piece::Color color, GameBoardModel* board) : Player {color, board} {};
public:
	GameBoardModel::PutStatus putPiece() override;
};

