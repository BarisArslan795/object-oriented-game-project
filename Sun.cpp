#include "olcSimpleEngine.h"
#include "Sun.h"
#include "Game.h"

using namespace std;

Sun::Sun(int X, int Y, game& PG) : x(X), y(Y), pG(&PG)
{
    img = new olc::Sprite("Sprites/sun1.png");
    pG->addSun(this);
};

Sun::~Sun() {
    pG->removeSun(this);
}

int Sun::distance(int xIn, int yIn) {
    return sqrt(pow(x + 20 - xIn, 2) + pow(y + 20 - yIn, 2));
};

bool Sun::collectSun() {
    if (distance(pG->GetMouseX(), pG->GetMouseY()) < 20) {
        pG->changeSunPoints(-value);
        return true;
    }
    return false;
}

void Sun::draw() {
    pG->DrawSprite(x, y, img, 1);
}