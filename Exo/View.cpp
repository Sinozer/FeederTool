#include "View.h"
#include "Button.h"

#include "ApplicationManager.h"

View::View(bool isActive,
	int x, int y, int w, int h,
	int colorR, int colorG, int colorB, int colorA)
{
	this->active = isActive;
	this->setX(x);
	this->setY(y);
	this->setW(w);
	this->setH(h);
	this->setColorR(colorR);
	this->setColorG(colorG);
	this->setColorB(colorB);
	this->setColorA(colorA);
}

View::~View()
{

}

bool View::isActive()
{
	return this->active;
}
void View::setActive(bool isActive)
{
	this->active = isActive;
}

SDL_Rect& View::getRect()
{
	return this->rect;
}

View View::getParent()
{
	return this->parent;
}
void View::setParent(View* parent)
{
	this->parent = parent;
}

int View::getX()
{
	return this->rect.x;
}
void View::setX(int x)
{
	this->rect.x = x;
}

int View::getY()
{
	return this->rect.y;
}
void View::setY(int y)
{
	this->rect.y = y;
}

int View::getW()
{
	return this->rect.w;
}
void View::setW(int w)
{
	this->rect.w = w;
}

int View::getH()
{
	return this->rect.h;
}
void View::setH(int h)
{
	this->rect.h = h;
}

int View::getColorR()
{
	return this->colorR;
}
void View::setColorR(int colorR)
{
	if (colorR < 0) colorR = 0;
	else if (colorR > 255) colorR = 255;
	this->colorR = colorR;
}

int View::getColorG()
{
	return this->colorG;
}
void View::setColorG(int colorG)
{
	if (colorG < 0) colorG = 0;
	else if (colorG > 255) colorG = 255;
	this->colorG = colorG;
}

int View::getColorB()
{
	return this->colorB;
}
void View::setColorB(int colorB)
{
	if (colorB < 0) colorB = 0;
	else if (colorB > 255) colorB = 255;
	this->colorB = colorB;
}

int View::getColorA()
{
	return this->colorA;
}
void View::setColorA(int colorA)
{
	if (colorA < 0) colorA = 0;
	else if (colorA > 255) colorA = 255;
	this->colorA = colorA;
}

void View::handleEvents()
{
	if (!this->active) return;
	/*###### Views ######*/
	for (auto i = this->viewList.list.begin(); i != this->viewList.list.end(); i++)
	{
		i->second.handleEvents();
	}
	/*###### Views ######*/
	/*###### TextBoxs ######*/
	for (auto i = this->textBoxList.list.begin(); i != this->textBoxList.list.end(); i++)
	{
		i->second->handleEvents();
	}
	/*###### TextBoxs ######*/
	/*###### Buttons ######*/
	for (auto i = this->buttonList.list.begin(); i != this->buttonList.list.end(); i++)
	{
		i->second->handleEvents();
	}
	/*###### Buttons ######*/
}

void View::update()
{
	if (!this->active) return;
	/*###### Views ######*/
	for (auto i = this->viewList.list.begin(); i != this->viewList.list.end(); i++)
	{
		//cout << i->first << endl;
		i->second.update();
	}
	/*###### Views ######*/
	/*###### TextBoxs ######*/
	if (this->textBoxList.getLen() > 0)
	{
		for (auto i = this->textBoxList.list.begin(); i != this->textBoxList.list.end(); i++)
		{
			i->second->update();
		}
	}
	/*###### TextBoxs ######*/
	/*###### Buttons ######*/
	if (this->buttonList.getLen() > 0)
	{
		for (auto i = this->buttonList.list.begin(); i != this->buttonList.list.end(); i++)
		{
			i->second->update();
		}
	}
	/*###### Buttons ######*/
}

void View::render()
{
	if (!this->active) return;
	SDL_SetRenderDrawColor(ApplicationManager::application.getWindow()->renderer, this->colorR, this->colorG, this->colorB, this->colorA);
	SDL_RenderFillRect(ApplicationManager::application.getWindow()->renderer, &this->rect);

	/*###### Views ######*/
	for (auto i = this->viewList.list.begin(); i != this->viewList.list.end(); i++)
	{
		i->second.render();
	}
	/*###### Views ######*/
	/*###### TextBoxs ######*/
	if (this->textBoxList.getLen() > 0)
	{
		for (auto i = this->textBoxList.list.begin(); i != this->textBoxList.list.end(); i++)
		{
			i->second->render();
		}
	}
	/*###### TextBoxs ######*/
	/*###### Buttons ######*/
	if (this->buttonList.getLen() > 0)
	{
		for (auto i = this->buttonList.list.begin(); i != this->buttonList.list.end(); i++)
		{
			i->second->render();
		}
	}
	/*###### Buttons ######*/
}

/*###### View ######*/
Container<View>& View::getViews()
{
	return this->viewList;
}

void View::createView(const char* name, bool isActive,
	int x, int y, int w, int h,
	int colorR, int colorG, int colorB, int colorA)
{
	this->viewList.add(name, View::View(isActive, x, y, w, h, colorR, colorG, colorB, colorA));
	this->viewList.getElement("name").setParent(this);
}
/*###### View ######*/

/*###### TextView ######*/
Container<TextBox*>& View::getTextBoxs()
{
	return this->textBoxList;
}

void View::createTextBox(const char* name,
	const char* text, bool isActive, bool isTitle,
	int x, int y, int w, int h,
	const char* vAlign, const char* hAlign,
	int colorR, int colorG, int colorB, int colorA)
{
	this->textBoxList.add(name, new TextBox(text, isActive, isTitle, x, y, w, h, vAlign, hAlign, colorR, colorG, colorB, colorA));
	this->textBoxList.getElement(name)->setParent(this);
}
/*###### TextView ######*/

/*###### Button ######*/
Container<Button*>& View::getButtons()
{
	return this->buttonList;
}

void View::createButton(const char* name, const char* text, function<void()> onClick,
	bool isActive, bool isTitle,
	int x, int y, int w, int h,
	const char* vAlign, const char* hAlign,
	int colorR, int colorG, int colorB, int colorA)
{
	this->buttonList.add(name, new Button(text, onClick, isActive, isTitle, x, y, w, h, vAlign, hAlign, colorR, colorG, colorB, colorA));
	this->buttonList.getElement(name)->setParent(this);
}
/*###### Button ######*/