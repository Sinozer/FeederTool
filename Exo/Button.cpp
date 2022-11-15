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
		&& y >= this->rect.y && y <= this->rect.h) this->hover = true;
	else this->hover = false;
	if (this->hover && lClick) this->clicked = true;
	else this->clicked = false;
}

void Button::update()
{
	if (!this->active) return;
	if (this->clicked) this->onClick();
}

void Button::render()
{
	if (!this->active) return;
	SDL_SetRenderDrawColor(ApplicationManager::application.getWindow()->renderer, this->colorR, this->colorG, this->colorB, this->colorA);
	SDL_RenderFillRect(ApplicationManager::application.getWindow()->renderer, &this->rect);

	SDL_SetRenderDrawColor(ApplicationManager::application.getWindow()->renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(ApplicationManager::application.getWindow()->renderer, &this->tRect);
	//cout << this->tRect.x << endl;
	SDL_RenderCopy(ApplicationManager::application.getWindow()->renderer, this->tTexture, NULL, &this->tRect);
}