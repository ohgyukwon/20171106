#pragma once

#include <iostream>
#include <SDL.h>
#include "TextureManager.h"

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	//SDL_Texture* m_pTexture;
	//SDL_Rect m_sourceRectangle;
	//SDL_Rect m_destinationRectangle;
	int m_currentFrame;
	TextureManager m_textureManager;
	bool m_bRunning;
};