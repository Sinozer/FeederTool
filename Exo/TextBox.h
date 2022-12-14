#pragma once

#include <ostream>
using namespace std;

#include "ApplicationManager.h"
#include "TextManager.h"

#include "Holder.h"

class TextBox : public Holder
{
protected:
	bool hover = false;
	bool clicked = false;

	bool isTitle;

	SDL_Rect tRect;
	SDL_Texture* tTexture;

	string text;
	const char* vAlign;
	const char* hAlign;
public:
	TextBox(string text, const char* tColor = "black", bool isActive = true, bool isTitle = false,
		int x = 0, int y = 0,
		int w = 0, int h = 0,
		const char* vAlign = "mid", const char* hAlign = "mid",
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255)
		: Holder(isActive, x, y, w, h, colorR,
			colorG, colorB, colorA) {
		this->text = text;
		this->isTitle = isTitle;
		this->vAlign = vAlign;
		this->hAlign = hAlign;
		this->tTexture = ApplicationManager::application.getWindow()->text->loadText(this->text, isTitle, tColor); //create TextBox
		this->updateTRect();
	};
	~TextBox();

	void setX(int x); //define x in SDL window
	void setY(int y);//define y in SDL window
	void setW(int w);//define w in SDL window
	void setH(int h);//define h in SDL window

	virtual void updateTRect(); //update a rectangle use for print the text

	void handleEvents() override;
	void update() override;
	void render() override;

	Container<Holder>& getHolders() = delete;
	void createHolder(const char* name,
		int x = 0, int y = 0,
		int w = 0, int h = 0,
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255) = delete;
	Container<Button>& getButtons() = delete;
	void createButton(const char* name,
		int x = 0, int y = 0,
		int w = 0, int h = 0,
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255) = delete;
};