#include "ComputerPlayer.h"
#include <random>

GameBoardModel::PutStatus ComputerPlayer::putPiece()
{
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution dis(0, 15);
	int x, y;
	while (true)
	{
		x = dis(eng);
		y = dis(eng);
		if (m_board->isValid(x, y))
			break;
	}
	auto piece {new Piece{x, y, color()}};
	return m_board->putPiece(piece);

}
