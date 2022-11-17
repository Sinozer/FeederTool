#include "TextureManager.h"

#include "ApplicationManager.h"

SDL_Texture* TextureManager::loadTexture(const char* fileName)
{
	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(ApplicationManager::application.getWindow()->renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return texture;
}