#include "InputBox.h"

#include <iostream>
using namespace std;

#include "ApplicationManager.h"

InputBox::~InputBox()
{
}

void InputBox::handleEvents()
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

	//cout << "Hover: " << this->hover << endl;
	//cout << "Click: " << this->click << endl;
	//cout << "Focus: " << this->focus << endl;
}

void InputBox::updateTRect()
{
	SDL_QueryTexture(this->tTexture, NULL, NULL, &this->tRect.w, &this->tRect.h);
	/*cout << "w: " << this->tRect.w << endl;
	cout << "w: " << this->tRect.h << endl;*/
	if (this->vAlign == "top")
		this->tRect.y = this->rect.y;
	else if (this->vAlign == "bot")
		this->tRect.y = this->rect.y + this->rect.h - this->tRect.h;
	else // MID
		this->tRect.y = (this->rect.y + this->rect.h / 2) - this->tRect.h / 2;

	if (this->hAlign == "left")
		this->tRect.x = this->rect.x;
	else if (this->hAlign == "right")
		this->tRect.x = this->rect.x + this->rect.w - this->tRect.w;
	else // MID
		this->tRect.x = (this->rect.x + this->rect.w / 2) - this->tRect.w / 2;
}

void InputBox::update()
{
	if (!this->active) return;
	if (this->hover && this->click)
	{
		this->click = false;
		this->focus = true;
	}
	else if (!this->hover && this->click) this->focus = false;
	if (this->focus) this->text = ApplicationManager::application.both;
	this->tTexture = ApplicationManager::application.getWindow()->text->loadText(this->text, this->isTitle);
	this->updateTRect();
}

void InputBox::render()
{
	if (!this->active) return;
	SDL_SetRenderDrawColor(ApplicationManager::application.getWindow()->renderer, this->colorR, this->colorG, this->colorB, this->colorA);
	SDL_RenderFillRect(ApplicationManager::application.getWindow()->renderer, &this->rect);

	//SDL_SetRenderDrawColor(ApplicationManager::application.getWindow()->renderer, 0, 0, 255, 255);
	//SDL_RenderFillRect(ApplicationManager::application.getWindow()->renderer, &this->tRect);

	SDL_RenderCopy(ApplicationManager::application.getWindow()->renderer, this->tTexture, NULL, &this->tRect);
}