#pragma once
#include "olcSimpleEngine.h"
#include "vector"
#include "tile.h"
#include "Sun.h"
#include "Pea.h"
#include "Game.h"
#include "Card.h"
#include "sunflower.h"
#include "Nut.h"
#include "peashooter.h"

using namespace std;

tile::tile(int xIn, int yIn, game& PG) :x(xIn), y(yIn),  isSelected(false), pG(&PG) {
    pG->addTile(this);
};

tile::~tile() {
    delete plant;
    pG->removeTile(this);
}

double tile::distance(double xZombie, double yZombie)
{
    return sqrt(pow(x - xZombie, 2) + pow(y - yZombie, 2));
}

void tile::zombieUpdate(int xPlant, int yPlant) {
    pG->zombieCanAttack(xPlant, yPlant);
}

bool tile::isTherePlant(double xZombie, double yZombie) {

    return ((distance(xZombie, yZombie) < 5) && (plant != nullptr));
}

void tile::addPlant(Plant* pPl) {
    plant=pPl;
};

void tile::removePlant() {
    delete plant;
    plant = nullptr;
};

void tile::upgradePlant() {
    plant->upgrade();
}

void tile::chooseActionsTile(int xM, int yM, int CurrentSun, Button* pB) {
    if (xM > x && xM < x + 50 && yM > y && yM < y + 50)
        pG->changeSunPoints(pB->action(CurrentSun, plant, this));
}

void tile::sunCreation(int x, int y) {
    new Sun(x, y, *pG);
};

void tile::peaCreation(int x, int y) {
    new Pea(x, y, *pG);
};

void tile::getHurtInThisTile(int damage) {
    if (plant->plantGetHurt(damage)) {
        removePlant();
    }
};

void tile::drawThePlant() {
    if(plant != nullptr)
        plant->drawToGame(pG);
}

void tile::abilityPowerOfPlant(double fElapsedTime) {
    if (plant != nullptr)
        plant->abilityPower(fElapsedTime);
};

void tile::zombieSpawn() {
    pG->createZombie(y);
};

void tile::draw() {
    
   
        if (plant !=nullptr)
        {
            pG->DrawRect(x, y, 49, 49, olc::BLACK);
        }
        else
        {
            if (pG->GetMouseX() > x && pG->GetMouseX() < x + 50 && pG->GetMouseY() > y && pG->GetMouseY() < y + 50)
            {
                pG->DrawRect(x, y, 49, 49, olc::WHITE);
            }

            else {
                pG->DrawRect(x, y, 49, 49, olc::VERY_DARK_GREY);
            }
        }

    
};

void tile::createSunflower() {
    new Sunflower(x, y, *this);
};

void tile::createNut() {
    new Nut(x, y, *this);
};

void tile::createPeashooter() {
    new Peashooter(x, y, *this);

};