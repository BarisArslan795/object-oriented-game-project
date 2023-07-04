#pragma once
#include "vector"
#include "Game.h"
#include "Zombie.h"

using namespace std;


class Pea {

    double x;
    int y;
    olc::Sprite* image;
    game* pG;

    double speed;
    double damage;
public:
    Pea(double xIn, int yIn, game& PG);
    ~Pea();

    void draw();
    void peaAttack(double fElapsedTime, Zombie* pZ);
    void peaMove(double fElapsedTime);
};
