#pragma once

#include <SDL_image.h>

class TextureManager {
public:
	static SDL_Texture* loadTexture(const char* fileName);
};