#pragma once

#include "olcSimpleEngine.h"
#include "vector"
#include "nutCard.h"
#include "Game.h"

using namespace std;

nutCard::nutCard(int X, int Y, int COST, olc::Sprite* IMG, game& PG)
	:Card(X, Y, COST, IMG, PG)
{

};

void nutCard::planting(tile* pT) {
	pT->createNut();
};