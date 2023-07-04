#include "olcSimpleEngine.h"
#include "Card.h"
#include "tile.h"
#include "Sunflower.h"
#include "peashooter.h"
#include "Game.h"
using namespace std;

Card::Card(int X, int Y, int COST, olc::Sprite* IMG, game& PG)
    : Button(X,Y,COST,IMG,PG)
{
};


int Card::action(int CurrentSun, Plant* plant, tile* pT) {
    if (plant == nullptr) {
        if (isSelected && cost <= CurrentSun) {
            planting(pT);
            isSelected = false;
            return cost;
        }
    }
    return 0;
};
