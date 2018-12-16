#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams, int speed) :
SDLGameObject(pParams), m_speed(speed) {
	m_velocity.setY(0);
	m_velocity.setX(0);
	m_numFrames = 7;
}

void Enemy::draw() {
	SDLGameObject::draw();
}

void Enemy::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));
	if (m_position.getX() < 1200) {
		m_velocity.setX(m_speed);
	}
	else if (m_position.getX() > 0) {
		m_velocity.setX(-1300);
	}
	SDLGameObject::update();
}

void Enemy::clean() {
	SDLGameObject::clean();
}

void Enemy::handleInput() {
	
}