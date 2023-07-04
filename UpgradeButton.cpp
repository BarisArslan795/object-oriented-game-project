#include "UpgradeButton.h"


UpgradeButton::UpgradeButton(int X, int Y, int COST, olc::Sprite* IMG, game& PG) : Button(X,Y,COST,IMG,PG){}

int UpgradeButton::action(int CurrentSun, Plant* plant, tile* pT) {
	if (plant != nullptr)
		if (isSelected && cost <= CurrentSun) {
			pT->upgradePlant();
			isSelected = false;
			return cost;
		}
	return 0;
}
