#include "Monster.h"


void Monster::load(int x, int y, int width, int height, std::string textureID) {
	GameObject::load(x, y, width, height, textureID);
}

void Monster::draw(SDL_Renderer* pRenderer) {
	GameObject::draw(pRenderer);
}

void Monster::clean() {

}

void Monster::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 9));
	m_x += x_speed;
	m_y += y_speed;
	moveRightLeft(100);
}

void Monster::setMovingspeed(int x, int y) {
	GameObject::setMovingspeed(x, y);
}

void Monster::moveRightLeft(int dist) {
	GameObject::moveRightLeft(dist);
}