#include "Player.h"


Player::Player(const LoaderParams* pParams) :

	SDLGameObject(pParams) {

}

void Player::draw() {
	SDLGameObject::draw();
}

void Player::update() {
	m_velocity.setY(0);
	m_velocity.setX(0);
	handleInput();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 7));
	SDLGameObject::update();
}

void Player::clean() {

}

void Player::handleInput() {
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;

	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
	//	m_velocity.setX(3);
	//}
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
	//	m_velocity.setX(-3);
	//}
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
	//	m_velocity.setY(-3);
	//}
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
	//	m_velocity.setY(3);
	//}
}