#pragma once
#include "olcSimpleEngine.h"
#include "vector"
#include "Game.h"
#include "plant.h"
#include "tile.h"

using namespace std;

class Tile;



Plant::Plant(int xIn, int yIn, double hpIn, double workSpeedIn, double abilityCDIn, tile& PT) {
	pT = &PT;
	x = xIn;
	y = yIn;
	HP = hpIn;
	abilityCD = abilityCDIn;
	abilityRate = workSpeedIn;
	pT->addPlant(this);
};

Plant::~Plant() {
	pT->zombieUpdate(x, y);
}

bool Plant::plantGetHurt(int damageTaken) {
	HP -= damageTaken;
	if (HP <= 0) {
		return true;
	}
	return false;
};


void Plant::drawToGame(game* pG) {
	pG->DrawSprite(x,y,img,1);
}

