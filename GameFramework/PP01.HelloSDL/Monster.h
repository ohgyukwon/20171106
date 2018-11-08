#pragma once

#include "GameObject.h"

class Monster : public GameObject {
public:
	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
	void setMovingspeed(int x, int y);
	void moveRightLeft(int dist);
};