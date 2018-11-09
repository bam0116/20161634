#pragma once

#include "SDL.h"
#include <SDL_image.h>
#include <map>

class TextureManager
{
private:
	static TextureManager* s_plnstance;
	TextureManager() {}
public:
	~TextureManager() {}
	bool load(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);
	static TextureManager* Instance()
	{
		if (s_plnstance == 0)
		{
			s_plnstance = new TextureManager();
			return s_plnstance;
		}
		return s_plnstance;
	}
private:
	std::map<std::string, SDL_Texture*> m_textureMap;

};

typedef TextureManager TheTextureManager;