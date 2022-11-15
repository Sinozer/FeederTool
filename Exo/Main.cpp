#include "Utils.h"

#include "ApplicationManager.h"

const int FPSLimit = 66; // 66 = ~15fps | 33 + ~30fps | 16 = ~60fps

int main( int argc, char* args[] )
{
	/*ApplicationManager::application.createFeeder("test", time(0) + 600, 550);
	ApplicationManager::application.getFeeders().getElement("test").debug();*/
	

	ApplicationManager::application.getWindow()->createView("mainView", true, 2, 2, ApplicationManager::applicationW / 2 - 4, ApplicationManager::applicationH / 2 - 4, 255, 255, 255, 255);
	/*cout << ApplicationManager::application.getWindow()->getViews().getElement("test").getParent().getX() << endl;
	cout << ApplicationManager::application.getWindow()->getViews().getElement("test").getParent().getY() << endl;
	cout << ApplicationManager::application.getWindow()->getViews().getElement("test").getParent().getW() << endl;
	cout << ApplicationManager::application.getWindow()->getViews().getElement("test").getParent().getH() << endl;*/
	View& mainView = ApplicationManager::application.getWindow()->getViews().getElement("mainView");
	mainView.createView(
		"listFeeder", true,
		mainView.getX() + 5,
		mainView.getY() + 5,
		mainView.getW() / 3 - 10,
		mainView.getH() - 10,
		47, 50, 52, 127);
	mainView.getViews().getElement("listFeeder").createButton(
		"test", "Feeder", []() {cout << "TEST" << endl; },
		true, false,
		mainView.getViews().getElement("listFeeder").getX() + 2,
		mainView.getViews().getElement("listFeeder").getY() + 2,
		mainView.getViews().getElement("listFeeder").getW() - 4,
		mainView.getViews().getElement("listFeeder").getH() / 10
	);
	mainView.createView(
		"changeFeeder", true,
		mainView.getViews().getElement("listFeeder").getX() + mainView.getViews().getElement("listFeeder").getW() + 5,
		mainView.getY() + 5,
		(mainView.getW() * 2) / 3 - 5,
		mainView.getH() - 10,
		47, 50, 52, 127);
	mainView.getViews().getElement("changeFeeder").createTextBox(
		"title", "CHANGE PAGE", true, true,
		mainView.getViews().getElement("changeFeeder").getX() + 2,
		mainView.getViews().getElement("changeFeeder").getY() + 2,
		mainView.getViews().getElement("changeFeeder").getW() - 4,
		mainView.getViews().getElement("changeFeeder").getH() / 10
	);
	/*mainView.getViews().getElement("changeFeeder").createView(
		"main", true,
		mainView.getViews().getElement("changeFeeder").getX(),
		mainView.getViews().getElement("changeFeeder").getTextBoxs().getElement("title").getY() + 5,
		(mainView.getViews().getElement("changeFeeder").getW() * 2) / 3 - 5,
		mainView.getViews().getElement("changeFeeder").getH() - 10,
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