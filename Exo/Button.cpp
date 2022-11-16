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


	cout << "-----------------" << endl;
	cout << this->hover << endl;
	cout << "-----------------" << endl;
	cout << (x >= this->rect.x) << endl;
	cout << (x <= this->rect.x + this->rect.w) << endl;
	cout << "-----------------" << endl;
	cout << (y >= this->rect.y) << endl;
	cout << (y <= this->rect.y + this->rect.h) << endl;
	cout << "-----------------" << endl;
	cout << this->rect.x << endl;
	cout << this->rect.x + this->rect.w << endl;
	cout << this->rect.y << endl;
	cout << this->rect.y + this->rect.h << endl;
	cout << "-----------------" << endl;
	cout << x << endl;
	cout << y << endl;
	cout << "-----------------" << endl;

	if (x >= this->rect.x && x <= this->rect.x + this->rect.w
		&& y >= this->rect.y && y <= this->rect.y + this->rect.h) this->hover = true;
	else this->hover = false;
	if (this->hover && lClick) this->click = true;
	else this->click = false;
}

void Button::update()
{	
	if (!this->active) return;
	if (this->click)
	{
		this->click = false;
		this->onClick();
	}
	else if (!this->click) this->click = false;
}

void Button::render()
{
	if (!this->active) return;
	SDL_SetRenderDrawColor(ApplicationManager::application.getWindow()->renderer, this->colorR, this->colorG, this->colorB, this->colorA);
	SDL_RenderFillRect(ApplicationManager::application.getWindow()->renderer, &this->rect);

	//SDL_SetRenderDrawColor(ApplicationManager::application.getWindow()->renderer, 0, 0, 255, 255);
	//SDL_RenderFillRect(ApplicationManager::application.getWindow()->renderer, &this->tRect);

	SDL_RenderCopy(ApplicationManager::application.getWindow()->renderer, this->tTexture, NULL, &this->tRect);
}