#pragma once
#include "Player.h"

class ComputerPlayer : public Player
{
public:
	ComputerPlayer(Piece::Color color, GameBoardModel* board) : Player {color, board} {};
public:
	GameBoardModel::PutStatus putPiece() override;
};

