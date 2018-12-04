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
	if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[1]))) 
	{
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
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
	if (!TheTextureManager::Instance()->load("Assets/wall.png", "wall", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("Assets/g_ground.png", "ground", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* player = new Player(new LoaderParams(500, 500, 30,30, "player"));
	GameObject* wall = new Enemy(new LoaderParams(800, 600, 50, 50, "wall"));
	GameObject* ground1 = new Enemy(new LoaderParams(0, 0, 1200, 100, "ground"));
	GameObject* ground2 = new Enemy(new LoaderParams(0, 700, 1200, 100, "ground"));
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(wall);
	m_gameObjects.push_back(ground1);
	m_gameObjects.push_back(ground2);
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	TheTextureManager::Instance()->clearFromTextureMap("wall");
	TheTextureManager::Instance()->clearFromTextureMap("ground");
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
