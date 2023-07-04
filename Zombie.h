#pragma once
#include "vector"
#include "Game.h"

using namespace std;

class game;
class Plant;

class Zombie  {
	
	game* pG;
	double x;
	int y;
	bool canAttack = false;
	double HP;
	double speed;
	double attackSpeed;
	double attackCD;
	double damage;
	olc::Sprite* image;

public:

	Zombie(int xIn, int yIn, game& PG);
	~Zombie();
	void draw();
	void zombieAttack(float fElapsedTime, tile* pT);
	void zombieMove(float fElapsedTime);
	double distance(double xIn, double yIn);
	bool isThereZombie(double xIn, double yIn);
	bool zombieGetHurt(double peaDamage);
	bool ZombieWin();
	void zombieCanAttackUpdate(int xPlantIn, int yPlantIn);
};