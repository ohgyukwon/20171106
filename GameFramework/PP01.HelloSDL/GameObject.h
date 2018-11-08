#pragma once

#include <SDL.h>
#include <string>
#include <map>
#include <SDL_image.h>
#include <vector>

class GameObject {
public:
	virtual void load(int x, int y, int width, int height, std::string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();
	virtual void setMovingspeed(int x, int y);
	virtual void moveRightLeft(int dist);
protected:
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int init_x;
	int init_y;
	int x_speed;
	int y_speed;
	int m_width;
	int m_height;
};