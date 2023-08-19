#pragma once
#include "Piece.h"

class GameBoardModel;

class  GameBoardView
{
private:
	GameBoardModel* m_model;
public:
	GameBoardView(GameBoardModel* model) : m_model {model} {};
public:
	void setModel(GameBoardModel* model) { m_model = model; }
	auto model() const { return m_model; }
public:
	virtual void showBoard() = 0;
};

