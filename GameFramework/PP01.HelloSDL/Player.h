#pragma once

#include <iostream>
#include "GameObject.h"
#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
private:
	void handleInput();
};