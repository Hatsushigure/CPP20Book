#pragma once
#include "GameBoardView.h"

class GameBoardViewConsole : public GameBoardView
{
private:
	const char* WhitePiece {"()"};
	const char* BlackPiece {"[]"};
public:
	GameBoardViewConsole(GameBoardModel* model);
public:
	void showBoard() override;
};

