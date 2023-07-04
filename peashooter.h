#pragma once
#include "olcSimpleEngine.h"
#include "vector"
#include "Game.h"
#include "plant.h"
using namespace std;

class Plant;
class Pea;

class Peashooter : public Plant {

public:
    Peashooter(int xIn, int yIn, tile& PT);
    void abilityPower(double fElapsedTime);
    void upgrade();
};