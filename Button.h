#pragma once
#include "Plant.h"
class game;

class Button {
protected:
	int x;
	int y;
	olc::Sprite* img;
	game* pG;
	bool isSelected;
	int cost;
public:
	Button(int x, int y, int cost, olc::Sprite* IMG, game& PG);
	~Button();	
	bool deSelect(bool anySelection);
	void select(bool anySelection);
	void draw();
	virtual int action(int CurrentSun, Plant* pP, tile* pT) = 0;

};