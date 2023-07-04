#pragma once

#include "olcSimpleEngine.h"
#include "vector"
#include "peaShooterCard.h"
#include "Game.h"

using namespace std;

peaShooterCard::peaShooterCard(int X, int Y, int COST, olc::Sprite* IMG, game& PG)
	:Card(X, Y, COST, IMG, PG)
{

};

void peaShooterCard::planting(tile* pT) {
	pT->createPeashooter();
};