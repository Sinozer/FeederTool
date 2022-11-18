#pragma once

#include <stdio.h>
#include <SDL.h>
#include <SDL_mixer.h>

#include "Container.h"

#include "View.h"
#include "TextManager.h"

class MainSDLWindow
{
protected:
	SDL_Window* window;

	Container<View*> viewList; //create a list of different view in the application
	View* currentView;
public:
	SDL_Renderer* renderer;
	TextManager* text;

	Mix_Music* EEG;

	MainSDLWindow(const char* title, int width, int height, bool fullScreen); //create the SDL window
	~MainSDLWindow(void);

	int init(const char* title, int width, int height, bool fullScreen); //initialize setting of the window
	
	View* getCurrentView(); //return the current view in the window
	void setCurrentView(View* view); //change view of the window

	void clearRenderer(void); //clear the window

	/*###### Holder ######*/
	Container<View*>& getViews(); //return list of different view
	void createView(const char* name, bool isActive);
	/*###### Holder ######*/
};