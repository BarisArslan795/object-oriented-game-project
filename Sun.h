#pragma once

class game;

class Sun {
	int x;
	int y;
	olc::Sprite* img;
	game* pG;
	int value = 50;
public:
	Sun(int X, int Y, game& PG);
	~Sun();
	void draw();
	bool collectSun();
	int distance(int x, int y);
};
