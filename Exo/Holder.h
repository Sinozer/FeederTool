#pragma once

#include <SDL.h>

#include <functional>
using namespace std;

#include "Container.h"

class TextBox;
class Button;
class InputBox;

class Holder {
protected:
	bool active = true;

	SDL_Rect rect;

	Holder* parent = nullptr;

	int colorR;
	int colorG;
	int colorB;
	int colorA;

	/*###### Holder ######*/
	Container<Holder> holderList;
	/*###### Holder ######*/

	/*###### Image ######*/
	Container<SDL_Texture*> imageList;
	/*###### Image ######*/

	/*###### TextBox ######*/
	Container<TextBox*> textBoxList;
	/*###### TextBox ######*/

	/*###### Button ######*/
	Container<Button*> buttonList;
	/*###### Button ######*/

	/*###### InputBox ######*/
	Container<InputBox*> inputBoxList;
	/*###### InputBox ######*/

public:
	Holder(bool isActive = true, int x = 0, int y = 0,
		int w = 0, int h = 0,
		int colorR = 255, int colorG = 255,					// Create holder
		int colorB = 255, int colorA = 255);
	~Holder();

	bool isActive();
	void setActive(bool isActive); //modify if the holder is active or not
	
	SDL_Rect& getRect(); //return an rectangle of SDL window

	Holder getParent(); //return the parent of the holder
	void setParent(Holder* parent); //modify the parent of the holder

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

	virtual void handleEvents(); //trigger on SDL event
	virtual void update(); //updated place Holder
	virtual void render(); //print SDL window

	/*###### Holder ######*/
	Container<Holder>& getHolders(); //return list of holder
	void createHolder(const char* name, bool isActive,
		int x = 0, int y = 0, int w = 0, int h = 0,
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255);
	/*###### Holder ######*/

	/*###### Image ######*/
	Container<SDL_Texture*>& getImages(); //return list of Images
	void createImage(const char* name, const char* fileName);
	/*###### Image ######*/

	/*###### TextBox ######*/
	Container<TextBox*>& getTextBoxs(); //return list of TextBox
	void createTextBox(const char* name,
		const char* text, const char* tColor, bool isActive = true, bool isTitle = false,
		int x = 0, int y = 0, int w = 0, int h = 0,
		const char* vAlign = "mid", const char* hAlign = "mid",
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255);
	/*###### TextBox ######*/

	/*###### Button ######*/
	Container<Button*>& getButtons(); //return list of Button
	void createButton(const char* name,
		const char* text, function<void()> onClick, bool isActive = true, bool isTitle = false,
		int x = 0, int y = 0, int w = 0, int h = 0,
		const char* vAlign = "mid", const char* hAlign = "mid",
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255);
	/*###### Button ######*/

	/*###### InputBox ######*/
	Container<InputBox*>& getInputBoxes(); //return list of InputBox
	void createInputBox(const char* name, bool isInt,
		const char* text, bool isActive = true, bool isTitle = false,
		int x = 0, int y = 0, int w = 0, int h = 0,
		const char* vAlign = "mid", const char* hAlign = "mid",
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255);
	/*###### InputBox ######*/
};