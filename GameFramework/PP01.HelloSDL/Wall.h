#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"

class Wall : public SDLGameObject {
public:
	Wall(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	void handleInput();
};