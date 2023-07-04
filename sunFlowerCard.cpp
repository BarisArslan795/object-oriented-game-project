#pragma once

#include "olcSimpleEngine.h"
#include "vector"
#include "sunFlowerCard.h"
#include "Game.h"
#include "sunflower.h"

using namespace std;

sunFlowerCard::sunFlowerCard(int X, int Y, int COST, olc::Sprite* IMG, game& PG)
	: Card(X,Y,COST, IMG, PG)
{
	
};

void sunFlowerCard::planting(tile* pT) {
	pT->createSunflower();
};
