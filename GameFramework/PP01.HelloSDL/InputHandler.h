#pragma once
#include "SDL.h"
#include <iostream>
#include "Vector2D.h"
#include "Game.h"

class InputHandler {

	enum mouse_buttons
	{
		LEFT = 0,
		MIDDLE = 1,
		RIGHT = 2
	};
public:
	const Uint8* m_keystates;
	bool isKeyDown(SDL_Scancode key);
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;
	bool getMouseButtonState(int buttonNumber);
	SDL_Event event;

	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	void update();
	void clean();
	void onMouseMove(SDL_Event event)
	{
		m_mousePosition->setX(event.motion.x);
		m_mousePosition->setY(event.motion.y);
	}
	void onMouseButtonDown(SDL_Event event)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			m_mouseButtonStates[LEFT] = true;
		}
		if (event.button.button == SDL_BUTTON_MIDDLE)
		{
			m_mouseButtonStates[MIDDLE] = true;
		}
		if (event.button.button == SDL_BUTTON_RIGHT)
		{
			m_mouseButtonStates[RIGHT] = true;
		}

	}
	void onMouseButtonUp(SDL_Event event)
	{
		if (event.button.button == SDL_BUTTON_LEFT)
		{
			m_mouseButtonStates[LEFT] = false;
		}
		if (event.button.button == SDL_BUTTON_MIDDLE)
		{
			m_mouseButtonStates[MIDDLE] = false;
		}
		if (event.button.button == SDL_BUTTON_RIGHT)
		{
			m_mouseButtonStates[RIGHT] = false;
		}

	}
	void onKeyDown()
	{
		m_keystates = SDL_GetKeyboardState(0);
	}
	void onKeyUp()
	{
		m_keystates = SDL_GetKeyboardState(0);
	}
	Vector2D* getMousePosition();
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;