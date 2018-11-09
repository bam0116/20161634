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
		//SDL_Surface* pTempSurface = IMG_Load("Assets/animate.png");
		SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");
		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);

		SDL_FreeSurface(pTempSurface);

		m_sourceRectangle.w = 128;
		m_sourceRectangle.h = 82;

		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;

		SDL_Surface* pTempSurface_2 = IMG_Load("Assets/animate-alpha.png");
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface_2);
		SDL_FreeSurface(pTempSurface_2);

		m_sourceRectangle_2.w = 128;
		m_sourceRectangle_2.h = 82;

		m_destinationRectangle_2.x = m_sourceRectangle_2.x = 0;
		m_destinationRectangle_2.y = 50;
		m_sourceRectangle_2.y = 0;
		m_destinationRectangle_2.w = m_sourceRectangle_2.w;
		m_destinationRectangle_2.h = m_sourceRectangle_2.h;
	}
	else
	{
		return false;
	}
	m_bRunning = true;
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture,
		&m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderCopy(m_pRenderer, m_pTexture,
		&m_sourceRectangle_2, &m_destinationRectangle_2);
	SDL_RenderPresent(m_pRenderer);
}
void Game::update()
{
	m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 150) % 6));
	m_destinationRectangle.x = 128 * int(((SDL_GetTicks() / 150)) % 6);

	m_sourceRectangle_2.x = 128 * int(((SDL_GetTicks() / 100) % 6));
	m_destinationRectangle_2.x = 128 * int(((SDL_GetTicks() / 100)) % 6);
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