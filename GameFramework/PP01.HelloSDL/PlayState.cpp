#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;


void PlayState::update() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
	for (int i = 1; i < m_gameObjects.size(); i++) {
		if (checkCollision(
			dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
			dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{
			TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}
	}
	
}

void PlayState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	if (!TheTextureManager::Instance()->load("Assets/player.png", "player", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/30x30.png", "30x30", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/60x30.png", "60x30", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/90x30.png", "90x30", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/180x30.png", "180x30", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/1200x30.png", "horizontal", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/30x800.png", "vertical", TheGame::Instance()->getRenderer())) {
		return false;
	}
	
	GameObject* player = new Player(new LoaderParams(100, 100, 30,30, "player")); m_gameObjects.push_back(player);
	GameObject* wall1 = new Enemy(new LoaderParams(100, 600, 30, 30, "30x30")); m_gameObjects.push_back(wall1);
	GameObject* wall2 = new Enemy(new LoaderParams(200, 600, 60, 30, "60x30")); m_gameObjects.push_back(wall2);
	GameObject* wall3 = new Enemy(new LoaderParams(300, 600, 90, 30, "90x30")); m_gameObjects.push_back(wall3);
	GameObject* wall4 = new Enemy(new LoaderParams(400, 600, 180, 30, "180x30")); m_gameObjects.push_back(wall4);
	GameObject* horizontal_bd1 = new Enemy(new LoaderParams(0, 0, 1200, 30, "horizontal")); m_gameObjects.push_back(horizontal_bd1);
	GameObject* horizontal_bd2 = new Enemy(new LoaderParams(0, 770, 1200, 30, "horizontal")); m_gameObjects.push_back(horizontal_bd2);
	GameObject* vertical_bd1 = new Enemy(new LoaderParams(0, 0, 30, 800, "vertical")); m_gameObjects.push_back(vertical_bd1);
	GameObject* vertical_bd2 = new Enemy(new LoaderParams(1170, 0, 30, 800, "vertical")); m_gameObjects.push_back(vertical_bd2);
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("player");
	TheTextureManager::Instance()->clearFromTextureMap("horizontal");
	TheTextureManager::Instance()->clearFromTextureMap("vertical");
	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2) {
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;

}
