#include "Application.h"
#include "ApplicationManager.h"
#include "TextureManager.h"

#include <windows.h>


SDL_Texture* testTexture;

Application::Application()
{
	this->timeCreated = time(0);

	this->window = new MainSDLWindow("Feeder tool", ApplicationManager::applicationW / 2, ApplicationManager::applicationH / 2, false);
	this->running = true;

	this->mouseX = 0;
	this->mouseY = 0;
	this->lClick = false;

	testTexture = TextureManager::loadTexture("test.png", this->window->renderer);
}

Application::~Application()
{
}

bool Application::isRunning()
{
	return this->running;
}

void Application::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			cout << "QUIT" << endl;
			this->running = false;
			break;
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&this->mouseX, &this->mouseY);
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT) this->lClick = true;
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT) this->lClick = false;
			break;
		default:
			break;
		}
		/*###### Holders ######*/
		for (auto i = this->window->getHolders().list.begin(); i != this->window->getHolders().list.end(); i++)
		{
			i->second.handleEvents();
		}
		/*###### Holders ######*/
	}
}

void Application::update()
{
	/*###### Holders ######*/
	for (auto i = this->window->getHolders().list.begin(); i != this->window->getHolders().list.end(); i++)
	{
		i->second.update();
	}
	/*###### Holders ######*/
}

void Application::render()
{
	this->window->clearRenderer();

	/*###### Holders ######*/
	for (auto i = this->window->getHolders().list.begin(); i != this->window->getHolders().list.end(); i++)
	{
		if (i->second.isActive()) i->second.render();
	}

	//SDL_RenderCopy(this->window->renderer, testTexture, NULL, NULL);
	/*###### Holders ######*/

	SDL_RenderPresent(this->window->renderer);
}

void Application::clean()
{
	this->window->~MainSDLWindow();
	SDL_Quit();
}

/*###### MainSDLWindow ######*/
MainSDLWindow* Application::getWindow()
{
	return this->window;
}
/*###### MainSDLWindow ######*/

/*###### Feeder ######*/
Container<Feeder>& Application::getFeeders()
{
	return this->feederList;
}

void Application::createFeeder(const char* name,
	time_t timeToTake, int quantity,
	bool eated, bool vomited)
{
	this->feederList.add(name, Feeder::Feeder(timeToTake, quantity, eated, vomited));
}
/*###### Feeder ######*/