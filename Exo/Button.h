#pragma once

#include <functional>
using namespace std;

#include <ostream>

#include "ApplicationManager.h"
#include "TextManager.h"

//#include "Holder.h"
#include "TextBox.h"

class Button : public TextBox
{
protected:
	bool hover = false;
	bool click = false;

	SDL_Rect tRect;
	SDL_Texture* tTexture;

	const char* text;
public:
	Button(const char* text, function<void()> onClick, bool isActive = true, bool isTitle = false, int x = 0, int y = 0,
		int w = 0, int h = 0,
		const char* vAlign = "mid", const char* hAlign = "mid",
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255)
		: TextBox(text, "black", isActive, isTitle, x, y, w, h, vAlign, hAlign,
			colorR, colorG, colorB, colorA) {
		this->text = text;
		this->onClick = onClick;
		this->tTexture = ApplicationManager::application.getWindow()->text->loadText(this->text);	//create Button
		SDL_QueryTexture(this->tTexture, NULL, NULL, &this->tRect.w, &this->tRect.h); //Query the attributes of a texture
		this->tRect.x = (this->rect.x + this->rect.w / 2) - this->tRect.w / 2;
		this->tRect.y = (this->rect.y + this->rect.h / 2) - this->tRect.h / 2;
	};
	~Button();

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

	function<void()> onClick = [] {};
};