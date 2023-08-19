#include "ConsolePlayer.h"
#include "GameBoardModel.h"
#include <iostream>

GameBoardModel::PutStatus ConsolePlayer::putPiece()
{
	using std::cout, std::cin;
	int x, y;
	cout << "You are " << (color() == Piece::Black ? "BLACK\n" : "WHITE\n");
	while (true)
	{
		cout << "Please enter the row number: ";
		cin >> y;
		cout << "Please enter the column number: ";
		cin >> x;
		if (m_board->isValid(x, y))
			break;
		cout << "Invalid input!\n";
	}
	auto piece {new Piece{x, y, color()}};
	return m_board->putPiece(piece);
}
