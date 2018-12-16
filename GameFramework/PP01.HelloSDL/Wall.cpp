#include "Wall.h"

Wall::Wall(const LoaderParams* pParams) :
	SDLGameObject(pParams) {
	m_velocity.setY(0);
	m_velocity.setX(0);
	m_numFrames = 7;
}

void Wall::draw() {
	SDLGameObject::draw();
}

void Wall::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	SDLGameObject::update();
}

void Wall::clean() {
	SDLGameObject::clean();
}

void Wall::handleInput() {

}