#include <iostream>
#include "Game.h"
#include <SDL_image.h>

Game::Game() {}

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{


		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true;
		if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

		m_gameObject.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		m_gameObject.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
	}
	else
	{
		return false;
	}
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObject.size(); i++)
	{
		m_gameObject[i]->draw();
	}
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObject.size(); i++)
	{
		m_gameObject[i]->update();
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}