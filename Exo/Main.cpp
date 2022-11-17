#include "Utils.h"

#include "ApplicationManager.h"
#include "Biberon.h"
#include <SDL_mixer.h>

const int FPSLimit = 66; // 66 = ~15fps | 33 + ~30fps | 16 = ~60fps

int main(int argc, char* args[])
{
	MainSDLWindow* window = ApplicationManager::application.getWindow();

	window->createView("MAIN", true);
	View* mainView = window->getViews().getElement("MAIN");

	mainView->createHolder(
		"MAIN", true,
		10, 10,
		ApplicationManager::applicationW / 2 - 20, ApplicationManager::applicationH / 2 - 20,
		0, 0, 0, 0
	);
	Holder& mainHolder = mainView->getHolders().getElement("mainHolder");

	/*mainHolder.createHolder(
		"FEEDER_IMAGE", true,
		mainHolder.getW() / 4, mainHolder.getH() / 4,
		mainHolder.getW() / 4, mainHolder.getH() / 4,

		);*/

	/*{
		ApplicationManager::application.getWindow()->createView("MAIN", false);
		View* mainView = ApplicationManager::application.getWindow()->getViews().getElement("MAIN");
		mainView->createHolder("mainHolder", true, 2, 2, ApplicationManager::applicationW / 2 - 4, ApplicationManager::applicationH / 2 - 4, 255, 255, 255, 255);
		Holder& mainHolder = mainView->getHolders().getElement("mainHolder");
		mainHolder.createHolder(
			"1", true,
			mainHolder.getX() + 5,
			mainHolder.getY() + 5,
			mainHolder.getW() / 3 - 10,
			mainHolder.getH() - 10,
			47, 50, 52, 127);
		mainHolder.getHolders().getElement("1").createButton(
			"2", "Feeder", []() { ApplicationManager::application.getWindow()->setCurrentView(ApplicationManager::application.getWindow()->getViews().getElement("5")); cout << "A" << endl; },
			true, false,
			mainHolder.getHolders().getElement("1").getX() + 2,
			mainHolder.getHolders().getElement("1").getY() + 2,
			mainHolder.getHolders().getElement("1").getW() - 4,
			mainHolder.getHolders().getElement("1").getH() / 10
		);
		mainHolder.createHolder(
			"3", true,
			mainHolder.getHolders().getElement("1").getX() + mainHolder.getHolders().getElement("1").getW() + 5,
			mainHolder.getY() + 5,
			(mainHolder.getW() * 2) / 3 - 5,
			mainHolder.getH() - 10,
			47, 50, 52, 127);
		mainHolder.getHolders().getElement("3").createImage("test", "test.png");
		mainHolder.getHolders().getElement("3").createTextBox(
			"4", "FIRST", true, true,
			mainHolder.getHolders().getElement("3").getX() + 2,
			mainHolder.getHolders().getElement("3").getY() + 2,
			mainHolder.getHolders().getElement("3").getW() - 4,
			mainHolder.getHolders().getElement("3").getH() / 10,
			"mid", "mid"
		);
		mainHolder.getHolders().getElement("3").createInputBox(
			"5", false, "OUIFI", true, false,
			mainHolder.getHolders().getElement("3").getX() + 2,
			mainHolder.getHolders().getElement("3").getY() + 200,
			mainHolder.getHolders().getElement("3").getW() - 4,
			mainHolder.getHolders().getElement("3").getH() / 10,
			"mid", "left"
		);
		mainHolder.getHolders().getElement("3").createInputBox(
			"6", false, "NONFI", true, false,
			mainHolder.getHolders().getElement("3").getX() + 2,
			mainHolder.getHolders().getElement("3").getY() + 300,
			mainHolder.getHolders().getElement("3").getW() - 4,
			mainHolder.getHolders().getElement("3").getH() / 10,
			"mid", "left"
		);
	}*/
	{
		ApplicationManager::application.getWindow()->createView("5", false);
		ApplicationManager::application.getWindow()->getViews().getElement("5")->createHolder("secondHolder", true, 2, 2, ApplicationManager::applicationW / 2 - 4, ApplicationManager::applicationH / 2 - 4, 255, 255, 255, 255);
		Holder& secondHolder = ApplicationManager::application.getWindow()->getViews().getElement("5")->getHolders().getElement("secondHolder");
		secondHolder.createHolder(
			"6", true,
			secondHolder.getX() + 5,
			secondHolder.getY() + 5,
			secondHolder.getW() / 3 - 10,
			secondHolder.getH() - 10,
			255, 50, 52, 127);
		secondHolder.getHolders().getElement("6").createButton(
			"7", "Other", []() { ApplicationManager::application.getWindow()->setCurrentView(ApplicationManager::application.getWindow()->getViews().getElement("MAIN")); cout << "B" << endl; },
			true, false,
			secondHolder.getHolders().getElement("6").getX() + 2,
			secondHolder.getHolders().getElement("6").getY() + 2,
			secondHolder.getHolders().getElement("6").getW() - 4,
			secondHolder.getHolders().getElement("6").getH() / 10
		);
		secondHolder.createHolder(
			"8", true,
			secondHolder.getHolders().getElement("6").getX() + secondHolder.getHolders().getElement("6").getW() + 5,
			secondHolder.getY() + 5,
			(secondHolder.getW() * 2) / 3 - 5,
			secondHolder.getH() - 10,
			47, 50, 52, 127);
		secondHolder.getHolders().getElement("8").createTextBox(
			"9", "CHANGE PAGE", true, true,
			secondHolder.getHolders().getElement("8").getX() + 2,
			secondHolder.getHolders().getElement("8").getY() + 2,
			secondHolder.getHolders().getElement("8").getW() - 4,
			secondHolder.getHolders().getElement("8").getH() / 10
		);
	}

	/*ApplicationManager::application.stock.createProduct("test", 12);
	cout << ApplicationManager::application.stock.getProducts().getElement("test")->getName() << endl;
	ApplicationManager::application.stock.modifyProduct("test", "otherTest", 12);
	cout << ApplicationManager::application.stock.getProducts().getElement("otherTest")->getName() << endl;*/

	if (SDL_Init(SDL_INIT_VIDEO) < 0)return -1;

	if (Mix_OpenAudio(96000, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur initialisation SDL_mixer : %s", Mix_GetError());
		SDL_Quit();
		return -1;
	}

	Mix_Music* music = Mix_LoadMUS("secret.mp3");

	if (music == nullptr)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
		Mix_CloseAudio();
		SDL_Quit();
		return -1;
	}

	Mix_PlayMusic(music, -1);
	Mix_FreeMusic(music);
	//Mix_CloseAudio(); //stop l'audio

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