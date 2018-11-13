#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Enemy::draw()
{
	SDLGameObject::draw(); // we now use SDLGameObject
}
void Enemy::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	SDLGameObject::update();
}
void Enemy::clean()
{
}
void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(0))
	{
		m_velocity.setX(1);
	}
	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;
}