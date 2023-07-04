#include "olcSimpleEngine.h"
#include "vector"
#include "Nut.h"
#include "Game.h"

using namespace std;

Nut::Nut(int xIn, int yIn, tile& PT)
    : Plant(xIn, yIn, 200, 0, 0, PT) {
    PT.addPlant(this);
    img = new olc::Sprite("Sprites/nut1.png");
    upgradedImage = new olc::Sprite("Sprites/upgradeNut.png");
};

void Nut::abilityPower(double fElapsedTime) {
};

void Nut::upgrade() {
    img = upgradedImage;
    HP = HP * (1.5);
};