#include "GameController.h"
#include "GameBoardViewConsole.h"
#include "GameBoardModel.h"
#include "ConsolePlayer.h"
#include "ComputerPlayer.h"
#include <iostream>


int main()
{
	auto model {new GameBoardModel};
	auto view {new GameBoardViewConsole {model}};
	auto p1 {new ComputerPlayer {Piece::Black, model}};
	//auto p1 {new ConsolePlayer {Piece::Black, model}};
	auto p2 {new ComputerPlayer {Piece::White, model}};
	//auto p2 {new ConsolePlayer {Piece::White, model}};
	auto controller {new GameController {view, p1, p2}};
	int black {0};
	for (auto i = 0; i < 100000000; i++)
	{
		(*model) = GameBoardModel();
		auto ret = controller->startGame();
		if (ret == Piece::Black)
		{
			std::cout << "Black Won!\n";
			black++;
		}
		else
			std::cout << "White Won!\n";
	}
	std::cout << "black won " << black << " times\n";
	std::cout << "white won " << 100000000 - black << " times\n";
}
