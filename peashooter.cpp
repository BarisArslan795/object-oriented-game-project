#pragma once
#include "olcSimpleEngine.h"
#include "vector"
#include "peashooter.h"
#include "Game.h"

class Plant;
class Pea;
class Peashooter;


using namespace std;

Peashooter::Peashooter(int xIn, int yIn, tile& PT)
    : Plant(xIn, yIn, 100, 5, 3, PT) {
    PT.addPlant(this);
    img = new olc::Sprite("Sprites/peashooter1.png");
    upgradedImage = new olc::Sprite("Sprites/upgradePeashooter.png");
};

void Peashooter::abilityPower(double fElapsedTime) {
    abilityCD -= fElapsedTime;
    if (abilityCD <= 0) {
        pT->peaCreation(x, y);
        abilityCD = abilityRate;
    }
};

void Peashooter::upgrade() {
    img = upgradedImage;
    abilityRate = abilityRate / 2;
};