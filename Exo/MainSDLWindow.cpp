#include "MainSDLWindow.h"
#include "ApplicationManager.h"
#include "Utils.h"

MainSDLWindow::MainSDLWindow(const char* title, int width, int height, bool fullScreen)
{
	this->window = NULL;
	this->renderer = NULL;
	this->text = NULL;
	this->EEG = NULL;

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
	if (this->EEG != NULL)
		Mix_CloseAudio();
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
	if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
		Utils::SDL_ExitWithError("Erreur initialisation SDL_mixer");
	this->EEG = Mix_LoadMUS("secret.mp3");
	if (this->EEG == nullptr)
	{
		Mix_CloseAudio();
		Utils::SDL_ExitWithError("Erreur chargement de la musique");
	}

	this->text = new TextManager(this->renderer, "LouisGeorgeCafeBold.ttf");

	return 0;
}

View* MainSDLWindow::getCurrentView()
{
	return this->currentView;
}
void MainSDLWindow::setCurrentView(View* view)
{
	this->currentView = view;
	ApplicationManager::application.lClick = false;
}

void MainSDLWindow::clearRenderer()
{
	if (SDL_SetRenderDrawColor(this->renderer, 47, 50, 52, 255) != 0)
		Utils::SDL_ExitWithError("SetRenderDrawColor");
	if (SDL_RenderClear(this->renderer) != 0)
		Utils::SDL_ExitWithError("RenderClear");
}

/*###### Holder ######*/
Container<View*>& MainSDLWindow::getViews()
{
	return this->viewList;
}

void MainSDLWindow::createView(const char* name, bool isActive)
{
	View* view = new View();
	this->viewList.add(name, view);
	if (isActive) this->currentView = view;
}
/*###### Holder ######*/