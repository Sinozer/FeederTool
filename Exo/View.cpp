#include "View.h"

View::View()
{

}

View::~View()
{

}

/*###### Holder ######*/
Container<Holder>& View::getHolders()
{
	return this->holderList;
}

void View::createHolder(const char* name, bool isActive,
	int x, int y, int w, int h,
	int colorR, int colorG, int colorB, int colorA)
{
	this->holderList.add(name, Holder::Holder(isActive, x, y, w, h, colorR, colorG, colorB, colorA));
}
/*###### Holder ######*/