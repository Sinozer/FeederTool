#include "Button.h"

#include <iostream>
using namespace std;

#include "ApplicationManager.h"

Button::~Button()
{
}

void Button::handleEvents()
{
	if (!this->active) return;
	int x = ApplicationManager::application.mouseX;
	int y = ApplicationManager::application.mouseY;
	bool lClick = ApplicationManager::application.lClick;

	if (x >= this->rect.x && x <= this->rect.x + this->rect.w
		&& y >= this->rect.y && y <= this->rect.y + this->rect.h) this->hover = true;
	else this->hover = false;
	if (lClick) this->click = true;
	else this->click = false;
}

void Button::update()
{
	if (!this->active) return;
	if (this->hover && this->click)
	{
		this->click = false;
		this->onClick();
	}
	//else if (!this->click) this->click = false;
}

void Button::render()
{
	if (!this->active) return;
	SDL_SetRenderDrawColor(ApplicationManager::application.getWindow()->renderer, this->colorR, this->colorG, this->colorB, this->colorA);
	SDL_RenderFillRect(ApplicationManager::application.getWindow()->renderer, &this->rect);

	if (this->hover)
	{
		SDL_SetRenderDrawColor(ApplicationManager::application.getWindow()->renderer, 0, 0, 0, 24);
		SDL_RenderFillRect(ApplicationManager::application.getWindow()->renderer, &this->rect);
		SDL_SetRenderDrawColor(ApplicationManager::application.getWindow()->renderer, 0, 0, 255, 255);
		SDL_RenderDrawRect(ApplicationManager::application.getWindow()->renderer, &this->rect);
	}

	SDL_RenderCopy(ApplicationManager::application.getWindow()->renderer, this->tTexture, NULL, &this->tRect);
}