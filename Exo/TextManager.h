#pragma once

#include <SDL_ttf.h>
#include "ContainerVector.h"
#include <string>

class TextManager {
protected:
	SDL_Renderer* renderer;

	TTF_Font* titleFont;
	TTF_Font* buttonFont;

	ContainerVector<SDL_Texture*> textureList;

	SDL_Color white = { 255, 255, 255 };
	SDL_Color black = { 0, 0, 0 };
public:
	TextManager(SDL_Renderer* renderer, const char* fontPath);
	~TextManager();

	SDL_Texture* loadText(string text,
		bool fontType = false,
		const char* color = "black");
};