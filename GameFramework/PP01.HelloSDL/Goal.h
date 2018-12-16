#pragma once

#include "SDLGameObject.h"
#include "InputHandler.h"

class Goal : public SDLGameObject {
public:
	Goal(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
private:
	void handleInput();
};