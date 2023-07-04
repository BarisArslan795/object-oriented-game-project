#include "RemoveButton.h"

RemoveButton::RemoveButton(int X, int Y, int COST, olc::Sprite* IMG, game& PG) : Button(X, Y, COST, IMG, PG) {}

int RemoveButton::action(int CurrentSun, Plant* plant, tile* pT) {
	if (plant != nullptr)
		if(isSelected && cost <= CurrentSun){
			pT->removePlant();
			isSelected = false;
			return cost;
		}
	return 0;
}
