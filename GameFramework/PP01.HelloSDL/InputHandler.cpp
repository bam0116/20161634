#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler()
{

}

void InputHandler::clean()
{

}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
	if (m_keystates != 0) {
		if (m_keystates[key] == 1)
		{
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}


void InputHandler::update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYUP)
		{
			m_keystates = SDL_GetKeyboardState(0);
		}

		if (event.type == SDL_KEYDOWN)
		{
			m_keystates = SDL_GetKeyboardState(0);
		}
		if (event.type == SDL_QUIT)
		{
			Game::Instance()->quit();
		}
	}
}