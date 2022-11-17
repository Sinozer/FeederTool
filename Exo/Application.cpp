#include "Application.h"
#include "ApplicationManager.h"
#include "TextureManager.h"

#include <windows.h>
#include "DataManager.h"



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

const char* letters[30] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
"O", "P", "Q", "R", "S", "T", "U", "V", "V", "W", "X", "Y", "Z"};

const char* numbers[11] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

void Application::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
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
		case SDL_TEXTINPUT:
		{
			char c = event.text.text[0];

			if (c > 0 && isdigit(c))
			{
				this->numbers = this->numbers + c;
				this->both = this->both + c;
			}
			else if (c > 0)
			{
				this->letters = this->letters + c;
				this->both = this->both + c;
			}
			break;
		}
		default:
			break;
		}
		/*###### Holders ######*/
		for (auto i = this->window->getViews().list.begin(); i != this->window->getViews().list.end(); i++)
		{
			if (i->second == ApplicationManager::application.getWindow()->getCurrentView())
			{
				for (auto j = i->second->getHolders().list.begin(); j != i->second->getHolders().list.end(); j++)
				{
					j->second.handleEvents();
				}
			}
		}
		/*###### Holders ######*/
	}
}

void Application::update()
{
	/*###### Holders ######*/
	for (auto i = this->window->getViews().list.begin(); i != this->window->getViews().list.end(); i++)
	{
		if (i->second == ApplicationManager::application.getWindow()->getCurrentView())
		{
			for (auto j = i->second->getHolders().list.begin(); j != i->second->getHolders().list.end(); j++)
			{
				j->second.update();
			}
		}
	}
	/*###### Holders ######*/

	//DataManager::newDay();
	//DataManager::addFeeder(4, 2, 50, 150, false, true);
	//DataManager::removeFeeder(2);
	//DataManager::addProduct("petit pois", 50, 2);
	//DataManager::getCategory();
	//cout << "All: " << DataManager::getAll() << endl;
}

void Application::render()
{
	this->window->clearRenderer();

	/*###### Holders ######*/
	for (auto i = this->window->getViews().list.begin(); i != this->window->getViews().list.end(); i++)
	{
		if (i->second == ApplicationManager::application.getWindow()->getCurrentView())
		{
			for (auto j = i->second->getHolders().list.begin(); j != i->second->getHolders().list.end(); j++)
			{
				//cout << j->first << endl;
				j->second.render();
			}
		}
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