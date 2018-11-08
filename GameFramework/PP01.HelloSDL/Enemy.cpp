#include "Enemy.h"


void Enemy::load(int x, int y, int width, int height, std::string textureID) {
	GameObject::load(x, y, width, height, textureID);
}

void Enemy::draw(SDL_Renderer* pRenderer) {
	GameObject::draw(pRenderer);
}

void Enemy::clean() {

}

void Enemy::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_x += x_speed;
	m_y += y_speed;
}

void Enemy::setMovingspeed(int x, int y) {
	GameObject::setMovingspeed(x, y);
}