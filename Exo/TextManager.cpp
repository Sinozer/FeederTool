#include "TextManager.h"

TextManager::TextManager(SDL_Renderer* renderer, const char* fontPath)
{
	this->renderer = renderer;
	TTF_Init();
	this->titleFont = TTF_OpenFont(fontPath, 40);
	this->buttonFont = TTF_OpenFont(fontPath, 28);
}

TextManager::~TextManager()
{
	for (int i = 0; i < this->textureList.getLen(); i++) {
		SDL_DestroyTexture(this->textureList.getElement(i));
	}
	TTF_CloseFont(this->titleFont);
	TTF_CloseFont(this->buttonFont);
	TTF_Quit();
}

SDL_Texture* TextManager::loadText(string text,
	bool isTitle, const char* color)
{
	TTF_Font* usedFont = this->buttonFont;
	if (isTitle) usedFont = this->titleFont;
	SDL_Color usedColor = this->black;
	if (color == "white") usedColor = this->white;

	SDL_Surface* surface =
		TTF_RenderText_Blended(usedFont, text.c_str(), usedColor);
	SDL_Texture* texture =
		SDL_CreateTextureFromSurface(this->renderer, surface);
	
	this->textureList.add(texture);

	SDL_FreeSurface(surface);
	
	return texture;
}