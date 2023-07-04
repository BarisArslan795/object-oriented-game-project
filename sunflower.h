#pragma once
#include "olcSimpleEngine.h"
#include "vector"
#include "Game.h"
#include "plant.h"

using namespace std;

class Plant;

class Sunflower : public Plant {

public:
    Sunflower(int xIn, int yIn, tile& PT);
    void abilityPower(double fElapsedTime);
    void upgrade();
};