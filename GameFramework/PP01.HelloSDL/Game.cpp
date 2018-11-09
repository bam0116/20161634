#include <iostream>
#include "Game.h"
#include <SDL_image.h>


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
		m_go.load(100, 100, 128, 82, "animate");
		m_player.load(300, 300, 128, 82, "animate");

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
	m_go.draw(m_pRenderer);
	m_player.draw(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	m_go.update();
	m_player.update();
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