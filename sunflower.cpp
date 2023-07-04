#pragma once
#include "olcSimpleEngine.h"
#include "vector"
#include "sunflower.h"
#include "Game.h"

using namespace std;

Sunflower::Sunflower(int xIn, int yIn, tile& PT)
    : Plant(xIn, yIn, 100, 5, 3, PT) {
    PT.addPlant(this);
    img = new olc::Sprite("Sprites/sunflower1.png");
    upgradedImage = new olc::Sprite("Sprites/upgradeSunflower.png");
};

void Sunflower::abilityPower(double fElapsedTime) {
    abilityCD -= fElapsedTime;
    if (abilityCD <= 0) {
        abilityCD = abilityRate;
        pT->sunCreation(x, y);
    }
};

void Sunflower::upgrade() {
    img = upgradedImage;
    abilityRate = abilityRate / 2;
};