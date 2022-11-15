#include "Utils.h"

#include "ApplicationManager.h"

const int FPSLimit = 66; // 66 = ~15fps | 33 + ~30fps | 16 = ~60fps

int main( int argc, char* args[] )
{
	/*ApplicationManager::application.createFeeder("test", time(0) + 600, 550);
	ApplicationManager::application.getFeeders().getElement("test").debug();*/

	ApplicationManager::application.getWindow()->createHolder("mainHolder", true, 2, 2, ApplicationManager::applicationW / 2 - 4, ApplicationManager::applicationH / 2 - 4, 255, 255, 255, 255);
	/*cout << ApplicationManager::application.getWindow()->getHolders().getElement("test").getParent().getX() << endl;
	cout << ApplicationManager::application.getWindow()->getHolders().getElement("test").getParent().getY() << endl;
	cout << ApplicationManager::application.getWindow()->getHolders().getElement("test").getParent().getW() << endl;
	cout << ApplicationManager::application.getWindow()->getHolders().getElement("test").getParent().getH() << endl;*/
	Holder& mainHolder = ApplicationManager::application.getWindow()->getHolders().getElement("mainHolder");
	mainHolder.createHolder(
		"listFeeder", true,
		mainHolder.getX() + 5,
		mainHolder.getY() + 5,
		mainHolder.getW() / 3 - 10,
		mainHolder.getH() - 10,
		47, 50, 52, 127);
	mainHolder.getHolders().getElement("listFeeder").createButton(
		"test", "Feeder", []() {cout << time(0) << endl; },
		true, false,
		mainHolder.getHolders().getElement("listFeeder").getX() + 2,
		mainHolder.getHolders().getElement("listFeeder").getY() + 2,
		mainHolder.getHolders().getElement("listFeeder").getW() - 4,
		mainHolder.getHolders().getElement("listFeeder").getH() / 10
	);
	mainHolder.createHolder(
		"changeFeeder", true,
		mainHolder.getHolders().getElement("listFeeder").getX() + mainHolder.getHolders().getElement("listFeeder").getW() + 5,
		mainHolder.getY() + 5,
		(mainHolder.getW() * 2) / 3 - 5,
		mainHolder.getH() - 10,
		47, 50, 52, 127);
	mainHolder.getHolders().getElement("changeFeeder").createTextBox(
		"title", "CHANGE PAGE", true, true,
		mainHolder.getHolders().getElement("changeFeeder").getX() + 2,
		mainHolder.getHolders().getElement("changeFeeder").getY() + 2,
		mainHolder.getHolders().getElement("changeFeeder").getW() - 4,
		mainHolder.getHolders().getElement("changeFeeder").getH() / 10
	);
	/*mainHolder.getHolders().getElement("changeFeeder").createHolder(
		"main", true,
		mainHolder.getHolders().getElement("changeFeeder").getX(),
		mainHolder.getHolders().getElement("changeFeeder").getTextBoxs().getElement("title").getY() + 5,
		(mainHolder.getHolders().getElement("changeFeeder").getW() * 2) / 3 - 5,
		mainHolder.getHolders().getElement("changeFeeder").getH() - 10,
		47, 50, 52, 127);*/

	while (ApplicationManager::application.isRunning())
	{
		unsigned int frame_limit = SDL_GetTicks() + FPSLimit;
		Utils::SDL_Limit_FPS(frame_limit, FPSLimit);

		ApplicationManager::application.handleEvents();
		ApplicationManager::application.update();
		ApplicationManager::application.render();
	}

	ApplicationManager::application.clean();

	return 0;
}