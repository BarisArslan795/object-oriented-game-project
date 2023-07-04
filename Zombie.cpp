#pragma once
#include "olcSimpleEngine.h"
#include "vector"
#include "Zombie.h"
#include "Pea.h"
#include "plant.h"
#include "tile.h"

using namespace std;



Zombie::Zombie(int xIn, int yIn, game& PG) : x(xIn), y(yIn), pG(&PG) {
	HP = 100;
	speed = 10;
	attackSpeed = 4;
	attackCD = 0;
	damage = 5;
	image = new olc::Sprite("Sprites/zombie1.png");
	pG->addZombie(this);
};

Zombie::~Zombie() {
	pG->removeZombie(this);
}

double Zombie::distance(double xPea, double yPea)
{
	return sqrt(pow(x - xPea, 2) + pow(y - yPea, 2));
}

bool Zombie::isThereZombie(double xPea, double yPea) {
	return (distance(xPea, yPea) < 5);
};

void Zombie::draw() {
	pG->DrawSprite(x, y, image, 1);
};

void Zombie::zombieAttack(float fElapsedTime, tile* pT) {
	
	
	attackCD -= fElapsedTime;
	if (pT->isTherePlant(x,y))
	{
		canAttack = true;
		if (attackCD <= 0) {

			attackCD = attackSpeed;
			pT->getHurtInThisTile(damage); 
		}
	}
	else
		canAttack = canAttack || false;
};

void Zombie::zombieCanAttackUpdate(int xPlantIn, int yPlantIn) {
	if (distance(xPlantIn, yPlantIn) < 5)
		canAttack = false;
}

void Zombie::zombieMove(float fElapsedTime) {
	if (!canAttack) {
		x -= (speed * fElapsedTime);
	}
}

bool Zombie::zombieGetHurt(double peaDamage) {
	HP -= peaDamage;
	if (HP <= 0)
		return true;
	return false;
};

bool Zombie::ZombieWin() {
	if (x <= 0) {
		return true;
	}
	return false;
};
