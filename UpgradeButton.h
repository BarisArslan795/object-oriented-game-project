#pragma once
#include "Button.h"
#include "plant.h"

class UpgradeButton : public Button {

public:
	UpgradeButton(int X, int Y, int COST, olc::Sprite* IMG, game& PG);
	int action(int CurrentSun, Plant* plant, tile* pT);
};
