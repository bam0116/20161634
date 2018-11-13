#include "Game.h"

int main(int argc, char* argv[])
{
	std::cout << "game init attempt...\n";
	if (Game::Instance()->init("Chapter1", 100, 100, 640, 480, false))
	{
		std::cout << "game init success!\n";
		while (Game::Instance()->running())
		{
			Game::Instance()->handleEvents();
			Game::Instance()->update();
			Game::Instance()->render();
			SDL_Delay(10);
		}
	}
	else {
		std::cout << "game init failure - " << SDL_GetError() << "\n";
		return -1;
	}
	std::cout << "game closing...\n";
	Game::Instance()->clean();
	return 0;
}