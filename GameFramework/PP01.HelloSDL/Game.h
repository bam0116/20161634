#pragma once
#include <vector>
#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"



class Game
{
public:
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit();
	bool running() { return m_bRunning; }


	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

private:
	Game();
	static Game* s_pInstance;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	int m_currentFrame;
	std::vector<GameObject*> m_gameObject;
};


