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
	for (int i = 1; i < m_gameObjects.size() - 1; i++) {
		if (checkCollision(
			dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
			dynamic_cast<SDLGameObject*>(m_gameObjects[i])))
		{
			TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}
	}
	if (checkCollision(	// vector 범위 오류
		dynamic_cast<SDLGameObject*>(m_gameObjects[0]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[15])))
	{
		TheGame::Instance()->getStateMachine()->changeState(WinState::Instance());
	}
}

void PlayState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	if (!TheTextureManager::Instance()->load("Assets/player.png", "player", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/goal.png", "goal", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/30x30.png", "30x30", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/60x30.png", "60x30", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/90x30.png", "90x30", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/180x30.png", "180x30", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/1200x30.png", "horizontal", TheGame::Instance()->getRenderer())) return false;
	if (!TheTextureManager::Instance()->load("Assets/30x800.png", "vertical", TheGame::Instance()->getRenderer())) return false;
	
	GameObject* player = new Player(new LoaderParams(100, 100, 30,30, "player")); m_gameObjects.push_back(player);

	GameObject* enemy1 = new Enemy(new LoaderParams(-60, 150, 30, 30, "30x30"), 10); m_gameObjects.push_back(enemy1);
	GameObject* enemy2 = new Enemy(new LoaderParams(-60, 210, 60, 30, "60x30"), 12); m_gameObjects.push_back(enemy2);
	GameObject* enemy3 = new Enemy(new LoaderParams(-60, 270, 90, 30, "90x30"), 9); m_gameObjects.push_back(enemy3);
	GameObject* enemy4 = new Enemy(new LoaderParams(-60, 330, 180, 30, "180x30"), 8); m_gameObjects.push_back(enemy4);
	GameObject* enemy5 = new Enemy(new LoaderParams(-60, 390, 90, 30, "90x30"), 10); m_gameObjects.push_back(enemy5);
	GameObject* enemy6 = new Enemy(new LoaderParams(-60, 450, 180, 30, "180x30"), 8); m_gameObjects.push_back(enemy6);
	GameObject* enemy7 = new Enemy(new LoaderParams(-60, 510, 30, 30, "30x30"), 18); m_gameObjects.push_back(enemy7);
	GameObject* enemy8 = new Enemy(new LoaderParams(-60, 570, 60, 30, "60x30"), 12); m_gameObjects.push_back(enemy8);
	GameObject* enemy9 = new Enemy(new LoaderParams(-60, 630, 30, 30, "30x30"), 16); m_gameObjects.push_back(enemy9);
	GameObject* enemy10 = new Enemy(new LoaderParams(-60, 690, 90, 30, "90x30"), 11); m_gameObjects.push_back(enemy10);

	GameObject* horizontal_bd1 = new Wall(new LoaderParams(0, 0, 1200, 30, "horizontal")); m_gameObjects.push_back(horizontal_bd1);
	GameObject* horizontal_bd2 = new Wall(new LoaderParams(0, 770, 1200, 30, "horizontal")); m_gameObjects.push_back(horizontal_bd2);
	GameObject* vertical_bd1 = new Wall(new LoaderParams(0, 0, 30, 800, "vertical")); m_gameObjects.push_back(vertical_bd1);
	GameObject* vertical_bd2 = new Wall(new LoaderParams(1170, 0, 30, 800, "vertical")); m_gameObjects.push_back(vertical_bd2);

	//GameObject* goal = new Goal(new LoaderParams(30, 740, 30, 30, "goal")); m_gameObjects.push_back(goal);
	GameObject* goal = new Goal(new LoaderParams(200, 100, 30, 30, "goal")); m_gameObjects.push_back(goal);

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
