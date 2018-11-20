#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = 0;


void PlayState::update() {

}

void PlayState::render() {

}

bool PlayState::onEnter() {
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit() {
	std::cout << "exiting PlayState\n";
	return true;
}