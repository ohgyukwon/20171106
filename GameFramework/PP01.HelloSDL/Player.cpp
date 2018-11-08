#include "Player.h"


void Player::load(int x, int y, int width, int height, std::string textureID) {
	GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer) {
	GameObject::draw(pRenderer);
}

void Player::clean() {
	GameObject::clean();
}

void Player::update() {
	m_currentFrame = int(((SDL_GetTicks() / 50) % 6));
	m_x += x_speed;
	m_y += y_speed;
}

void Player::setMovingspeed(int x, int y) {
	GameObject::setMovingspeed(x, y);
}