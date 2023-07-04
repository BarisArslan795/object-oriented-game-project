#pragma once
#include "olcSimpleEngine.h"
#include "vector"
#include "Game.h"
#include "tile.h"
using namespace std;

class Plant {
protected:
	
	tile* pT;
	double HP;
	int x;
	int y;
	double abilityRate;
	double abilityCD;
	olc::Sprite* img = nullptr;
	olc::Sprite* upgradedImage = nullptr;

public:

	Plant(int xIn, int yIn, double hpIn, double abilityRateIn, double abilityCDIn, tile& PT);
	~Plant();

	void drawToGame(game* pG);
	bool plantGetHurt(int damageTaken);
	virtual void abilityPower(double fElapsedTime) = 0;
	virtual void upgrade() = 0;
};