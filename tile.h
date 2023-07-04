#pragma once
#include "vector"


class game;
class Plant;
class Button;
using namespace std;


class tile {
	int x;
	int y;
	game* pG;
	bool isSelected;
	
	Plant* plant = nullptr;

public:

	tile(int xIn, int yIn, game& PG);
	~tile();
	
	void addPlant(Plant* pPl);
	void removePlant();

	void sunCreation(int x, int y);
	void peaCreation(int x, int y);

	double distance(double xIn, double yIn);
	bool isTherePlant(double xZombie, double yZombie);
	void getHurtInThisTile(int damage);
	void abilityPowerOfPlant(double fElapsedTime);
	void drawThePlant();
	void chooseActionsTile(int xM, int yM, int CurrentSun, Button* pB);
	void draw();
	void zombieSpawn();
	void zombieUpdate(int xPlant, int yPlant);
	void upgradePlant();
	void createSunflower();
	void createPeashooter();
	void createNut();
};