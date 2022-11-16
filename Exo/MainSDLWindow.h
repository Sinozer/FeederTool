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

	Container<View*> viewList;
	View* currentView;
public:
	SDL_Renderer* renderer;
	TextManager* text;

	MainSDLWindow(const char* title, int width, int height, bool fullScreen);
	~MainSDLWindow(void);

	int init(const char* title, int width, int height, bool fullScreen);
	
	View* getCurrentView();
	void setCurrentView(View* view);

	void clearRenderer(void);

	/*###### Holder ######*/
	Container<View*>& getViews();
	void createView(const char* name, bool isActive);
	/*###### Holder ######*/
};