#include "Application.h"
#include "ApplicationManager.h"
#include "TextureManager.h"

#include <windows.h>
#include "DataManager.h"
#include "Stock.h"


SDL_Texture* testTexture;

Application::Application()
{
	this->timeCreated = time(0);

	this->window = new MainSDLWindow("Feeder tool", ApplicationManager::applicationW, ApplicationManager::applicationH, false);
	this->running = true;

	this->mouseX = 0;
	this->mouseY = 0;
	this->backSpace = false;
	this->lClick = false; this->bReturn = false;

	this->loadFeeders();
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
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_BACKSPACE:
				if (this->both.size() > 0)
				{
					this->both.erase(this->both.size() - 1);
				}
				this->backSpace = true;
				break;
			case SDLK_RETURN:
				this->bReturn = true;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_BACKSPACE:
				this->backSpace = false;
				break;
			case SDLK_RETURN:
				this->bReturn = false;
				break;
			default:
				break;
			}
			break;
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
ContainerVector<Feeder>& Application::getFeeders()
{
	/*for (auto i = 0; i < DataManager::getFeeders().size(); i++)
	{
		cout << DataManager::getFeeders()[i] << endl;
	}*/
	//this->feederList = DataManager::getFeeders();
	return this->feederList;
}

void Application::createFeeder(time_t timeToTake, int quantity,
	bool eated, bool vomited, time_t timeCreated, bool isLoad)
{
	this->feederList.add(Feeder::Feeder(timeToTake, quantity, eated, vomited));
	if (!isLoad)
		DataManager::addFeeder(this->feederList.getLen(), timeCreated, timeToTake, quantity, eated, vomited);
}

void Application::loadFeeders()
{
	for (json feeder : DataManager::getFeeders())
	{
		this->createFeeder(feeder["timeTaken"], feeder["quantity"], feeder["isEated"], feeder["isVomited"], feeder["timeCreated"], true);
	}
}
/*###### Feeder ######*/