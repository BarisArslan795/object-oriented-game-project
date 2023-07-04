#pragma once
#include "tile.h"
#include "Plant.h"
#include "Button.h"

class game;

class Card : public Button  {
public:
	Card(int X, int Y, int COST, olc::Sprite* IMG, game& PG);
	int action(int CurrentSun, Plant* pP, tile* pT);
	virtual void planting(tile* pT) = 0;
};