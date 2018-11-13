#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler()
{
	m_mousePosition = new Vector2D(0, 0);
	for (int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
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

bool InputHandler::getMouseButtonState(int buttonNumber)
{
	return m_mouseButtonStates[buttonNumber];
}

Vector2D*  InputHandler::getMousePosition()
{
	return m_mousePosition;
}

void InputHandler::update()
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			Game::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(event);
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;
		case SDL_KEYDOWN:
			onKeyDown();
			break;
		case SDL_KEYUP:
			onKeyUp();
			break;
		default:
			break;
		}
	}
}