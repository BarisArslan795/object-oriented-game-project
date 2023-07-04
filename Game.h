#pragma once
#include <vector>
#include "olcSimpleEngine.h" 

#include "Button.h"
#include "Sun.h"
#include "tile.h"
#include "Zombie.h"
#include "plant.h"
class Button;
class Sun; 
class tile; 
class Zombie;
class Pea;
class Plant;

using namespace std;

class game : public olc::PixelGameEngine {
	float spawnCD = 3;
	float spawnRate = 5;
	int CurrentSun = 100;
	int sunflowerCost = 50;
	int peashooterCost = 100;
	double gameTime;
	bool gameEnd;
	bool gamePause;
	bool anySelection;
	double finalCountDown;
	vector<Button*> buttons;
	vector<tile*> tiles;
	vector<Sun*> suns;
	vector<Zombie*> zombies;
	vector<Pea*> peas;
	


public:

	void addButton(Button* pC);
	void removeButton(Button* pC);
	
	void addSun(Sun* pS);
	void removeSun(Sun* pS);

	void addTile(tile* pT);
	void removeTile(tile* pT);
	
	void addZombie(Zombie* pZ);
	void removeZombie(Zombie* pZ);

	void addPea(Pea* pP);
	void removePea(Pea* pP);

	void createZombie(int y);
	bool OnUserUpdate(float fElapsedTime);
	bool OnUserCreate();
	bool gameExit();
	bool gameEndScreen();
	bool gamePauseScreen();
	bool countDownScreen(float fElapsedTime);
	void drawEverything();
	void createBackground();
	void drawRemainingSun();
	void changeSunPoints(int value);
	void zombieCanAttack(int xPlant, int yPlant);
};