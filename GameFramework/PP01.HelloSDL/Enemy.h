#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"

class Enemy : public SDLGameObject {
public:
	Enemy(const LoaderParams* pParams, int speed);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	void handleInput();
	int m_speed;
};