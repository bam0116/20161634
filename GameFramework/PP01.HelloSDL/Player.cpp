#include "Player.h"

Player::Player(const LoaderParams* pParams) :SDLGameObject(pParams) {}


void Player::draw()
{
	SDLGameObject::draw();
}
void Player::handleInput()
{
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}

}

void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}

void Player::clean()
{
}