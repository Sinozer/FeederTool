#include "MainSDLWindow.h"
#include "Utils.h"

MainSDLWindow::MainSDLWindow(const char* title, int width, int height, bool fullScreen)
{
	this->window = NULL;
	this->renderer = NULL;
	this->text = NULL;

	this->init(title, width, height, fullScreen);
	if (SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND) != 0)
		Utils::SDL_ExitWithError("SetRenderDrawBlendMode");
}

MainSDLWindow::~MainSDLWindow()
{
	if (this->text != NULL)
		text->~TextManager();
	if (this->renderer != NULL)
		SDL_DestroyRenderer(this->renderer);
	if (this->window != NULL)
		SDL_DestroyWindow(this->window);
}

int MainSDLWindow::init(const char* title, int width, int height, bool fullScreen)
{
	int windowSize = 0;
	if (fullScreen) windowSize = SDL_WINDOW_FULLSCREEN_DESKTOP;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		Utils::SDL_ExitWithError("Init");
	this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, windowSize);
	if (this->window == NULL)
		Utils::SDL_ExitWithError("CreateWindow");
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_SOFTWARE);
	if (this->renderer == NULL)
		Utils::SDL_ExitWithError("CreateRenderer");
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
	
	this->text = new TextManager(this->renderer, "LouisGeorgeCafeBold.ttf");
	
	return 0;
}

void MainSDLWindow::clearRenderer()
{
	if (SDL_SetRenderDrawColor(this->renderer, 47, 50, 52, 255) != 0)
		Utils::SDL_ExitWithError("SetRenderDrawColor");
	if (SDL_RenderClear(this->renderer) != 0)
		Utils::SDL_ExitWithError("RenderClear");
}

/*###### Holder ######*/
Container<Holder>& MainSDLWindow::getHolders()
{
	return this->holderList;
}

void MainSDLWindow::createHolder(const char* name, bool isActive, int x, int y,
	int w, int h, int colorR, int colorG,
	int colorB, int colorA)
{
	this->holderList.add(name, Holder::Holder(isActive, x, y, w, h, colorR, colorG, colorB, colorA));
}
/*###### Holder ######*/