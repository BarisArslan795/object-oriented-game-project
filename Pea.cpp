#include "olcSimpleEngine.h"
#include "vector"
#include "Zombie.h"
#include "Pea.h"

using namespace std;


Pea::Pea(double xIn, int yIn, game& PG) : x(xIn), y(yIn), pG(&PG){
    damage = 50;
    speed = 50;
    image = new olc::Sprite("Sprites/seed.png");

    pG->addPea(this);
};

Pea::~Pea() {
    pG->removePea(this);
};

void Pea::draw() {
    pG->DrawSprite(x, y, image, 1);
};

void Pea::peaAttack(double fElapsedTime, Zombie* pZ) {
    if (pZ->isThereZombie(x, y)) {
        if (pZ->zombieGetHurt(damage))
            delete pZ; 
        delete this;
    }
};

void Pea::peaMove(double fElapsedTime) {
    x += speed * fElapsedTime;
    if (x >= pG->ScreenWidth()) {
        delete this;
    }
}
