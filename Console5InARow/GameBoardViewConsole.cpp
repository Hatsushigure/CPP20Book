#include "GameBoardViewConsole.h"
#include "GameBoardModel.h"
#include <iostream>
#include <iomanip>

GameBoardViewConsole::GameBoardViewConsole(GameBoardModel* model)
	: GameBoardView {model}
{
}

void GameBoardViewConsole::showBoard()
{
	using std::cout, std::setw;
#ifdef _WIN32
	system("cls");
#endif // _WIN32
	cout << "   ";
	for (auto i = 0; i < model()->Width; i++)
		cout << setw(2) << i << ' ';
	for (auto i = 0; i < model()->Width; i++)
	{
		cout << '\n' << setw(2) << i << ' ';
		for (auto j = 0; j < model()->Width; j++)
		{
			auto piece {model()->findPieceAt(j, i)};
			if (piece == nullptr)
				cout << "   ";
			else if (piece->color() == Piece::Black)
				cout << BlackPiece << ' ';
			else
				cout << WhitePiece << ' ';
		}
	}
	cout << '\n';
}
