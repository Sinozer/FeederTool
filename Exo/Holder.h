#pragma once

#include <SDL.h>

#include <functional>
using namespace std;

#include "Container.h"

class TextBox;
class Button;

class Holder {
protected:
	bool active = true;

	SDL_Rect rect;

	Holder* parent;

	int colorR;
	int colorG;
	int colorB;
	int colorA;

	/*###### Holder ######*/
	Container<Holder> holderList;
	/*###### Holder ######*/

	/*###### TextBox ######*/
	Container<TextBox*> textBoxList;
	/*###### TextBox ######*/

	/*###### Button ######*/
	Container<Button*> buttonList;
	/*###### Button ######*/
public:
	Holder(bool isActive = true, int x = 0, int y = 0,
		int w = 0, int h = 0,
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255);
	~Holder();

	bool isActive();
	void setActive(bool isActive);

	SDL_Rect& getRect();

	Holder getParent();
	void setParent(Holder* parent);

	int getX();
	void setX(int x);

	int getY();
	void setY(int y);

	int getW();
	void setW(int w);

	int getH();
	void setH(int h);

	int getColorR();
	void setColorR(int colorR);

	int getColorG();
	void setColorG(int colorG);

	int getColorB();
	void setColorB(int colorB);

	int getColorA();
	void setColorA(int colorA);

	virtual void handleEvents();
	virtual void update();
	virtual void render();

	/*###### Holder ######*/
	Container<Holder>& getHolders();
	void createHolder(const char* name, bool isActive,
		int x = 0, int y = 0, int w = 0, int h = 0,
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255);
	/*###### Holder ######*/

	/*###### TextBox ######*/
	Container<TextBox*>& getTextBoxs();
	void createTextBox(const char* name,
		const char* text, bool isActive = true, bool isTitle = false,
		int x = 0, int y = 0, int w = 0, int h = 0,
		const char* vAlign = "mid", const char* hAlign = "mid",
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255);
	/*###### TextBox ######*/

	/*###### Button ######*/
	Container<Button*>& getButtons();
	void createButton(const char* name,
		const char* text, function<void()> onClick, bool isActive = true, bool isTitle = false,
		int x = 0, int y = 0, int w = 0, int h = 0,
		const char* vAlign = "mid", const char* hAlign = "mid",
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255);
	/*###### Button ######*/
};