#include "Goal.h"

Goal::Goal(const LoaderParams* pParams) :
	SDLGameObject(pParams) {
	m_velocity.setY(0);
	m_velocity.setX(0);
	m_numFrames = 7;
}

void Goal::draw() {
	SDLGameObject::draw();
}

void Goal::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	SDLGameObject::update();
}

void Goal::clean() {
	SDLGameObject::clean();
}

void Goal::handleInput() {

}