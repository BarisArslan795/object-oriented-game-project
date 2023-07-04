#pragma once
#include "olcSimpleEngine.h"
#include "vector"
#include "Game.h"
#include "Card.h"

using namespace std;

class Card;

class sunFlowerCard : public Card{
	
public:
	sunFlowerCard(int X, int Y, int COST, olc::Sprite* IMG, game& PG);
	void planting(tile* pT);

};
