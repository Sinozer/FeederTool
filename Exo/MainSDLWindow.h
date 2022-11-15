#pragma once

#include <stdio.h>
#include <SDL.h>

#include "Container.h"

#include "View.h"
#include "TextManager.h"

class MainSDLWindow
{
protected:
	SDL_Window* window;

	Container<View> viewList;
public:
	SDL_Renderer* renderer;
	TextManager* text;

	MainSDLWindow(const char* title, int width, int height, bool fullScreen);
	~MainSDLWindow(void);

	int init(const char* title, int width, int height, bool fullScreen);
	void clearRenderer(void);

	/*###### View ######*/
	Container<View>& getViews();
	void createView(const char* name, bool isActive,
		int x = 0, int y = 0,
		int w = 0, int h = 0,
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255);
	/*###### View ######*/
};