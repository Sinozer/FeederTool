#include "TextBox.h"

#include <iostream>
using namespace std;

#include "ApplicationManager.h"

TextBox::~TextBox()
{
}

void TextBox::updateTRect()
{
	SDL_QueryTexture(this->tTexture, NULL, NULL, &this->tRect.w, &this->tRect.h);
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
	cout << "rect.x: " << this->rect.x << endl;
	cout << "tRect.x: " << this->tRect.x << endl;
}

void TextBox::setX(int x)
{
	this->updateTRect();
}

void TextBox::setY(int y)
{
	this->updateTRect();
}

void TextBox::setW(int w)
{
	this->updateTRect();
}

void TextBox::setH(int h)
{
	this->updateTRect();
}

void TextBox::handleEvents()
{
}

void TextBox::update()
{
}

void TextBox::render()
{
	if (!this->active) return;
	SDL_SetRenderDrawColor(ApplicationManager::application.getWindow()->renderer, this->colorR, this->colorG, this->colorB, this->colorA);
	SDL_RenderFillRect(ApplicationManager::application.getWindow()->renderer, &this->rect);
	SDL_RenderCopy(ApplicationManager::application.getWindow()->renderer, this->tTexture, NULL, &this->tRect);
}