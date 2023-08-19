#include "GameController.h"
#include "GameBoardView.h"
#include "GameBoardModel.h"
#include "Player.h"

Piece::Color GameController::startGame()
{
	while (true)
	{
		view()->showBoard();
		auto ret {m_blackPlayer->putPiece()};
		view()->showBoard();
		if (ret == GameBoardModel::GameEnd)
			return Piece::Black;
		ret = m_whitePlayer->putPiece();
		view()->showBoard();
		if (ret == GameBoardModel::GameEnd)
			return Piece::White;
	}
}
