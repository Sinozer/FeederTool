#pragma once

#include "Container.h"

#include "Holder.h"

class View
{
protected:
	Container<Holder> holderList;
public:
	View();
	~View();

	/*###### Holder ######*/
	Container<Holder>& getHolders();
	void createHolder(const char* name, bool isActive,
		int x = 0, int y = 0, int w = 0, int h = 0,
		int colorR = 255, int colorG = 255,
		int colorB = 255, int colorA = 255);
	/*###### Holder ######*/
};