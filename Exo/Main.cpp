#include "Utils.h"

#include "ApplicationManager.h"
#include "DataManager.h"

//#include "Biberon.h"

#include "View.h"
#include "Holder.h"
#include "TextBox.h"
#include "Button.h"
#include "InputBox.h"
#include <SDL_mixer.h>

const int FPSLimit = 66; // 66 = ~15fps | 33 + ~30fps | 16 = ~60fps

int main(int argc, char* args[])
{
	MainSDLWindow* window = ApplicationManager::application.getWindow();

	{ // MAIN_VIEW
		window->createView("MAIN_VIEW", true);
		View* mainView = window->getViews().getElement("MAIN_VIEW");

		mainView->createHolder(
			"MAIN_HOLDER", true,
			10, 10,
			ApplicationManager::applicationW - 20, ApplicationManager::applicationH - 20,
			0, 0, 0, 0
		);
		Holder& mainHolder = mainView->getHolders().getElement("MAIN_HOLDER");

		mainHolder.createHolder(
			"FEEDER_IMAGE", true,
			(mainHolder.getX() + mainHolder.getW()) / 2.7, (mainHolder.getY() + mainHolder.getH()) / 8,
			mainHolder.getW() / 2, mainHolder.getH() / 2,
			255, 255, 255, 0
		);
		Holder& feederImageC = mainHolder.getHolders().getElement("FEEDER_IMAGE");

		feederImageC.createImage(
			"FEEDER_IMAGE", "Feeder.png"
		);

		mainHolder.createButton(
			"FEEDER_BUTTON", "Biberon",
			[]() { ApplicationManager::application.getWindow()->setCurrentView(ApplicationManager::application.getWindow()->getViews().getElement("FEEDER_VIEW")); },
			true, false,
			(mainHolder.getX() + mainHolder.getW()) / 4, (mainHolder.getY() + mainHolder.getH()) / 1.4,
			mainHolder.getW() / 2, mainHolder.getH() / 10,
			"mid", "mid", 255, 255, 255, 127
		);

		mainHolder.createButton(
			"STOCK_BUTTON", "Stock",
			[]() { ApplicationManager::application.getWindow()->setCurrentView(ApplicationManager::application.getWindow()->getViews().getElement("STOCK_VIEW")); },
			true, false,
			(mainHolder.getX() + mainHolder.getW()) / 4, (mainHolder.getY() + mainHolder.getH()) / 1.2,
			mainHolder.getW() / 2, mainHolder.getH() / 10,
			"mid", "mid", 255, 255, 255, 127
		);
	}
	{ // FEEDER_VIEW
		window->createView("FEEDER_VIEW", false);
		View* mainView = window->getViews().getElement("FEEDER_VIEW");

		mainView->createHolder(
			"MAIN_HOLDER", true,
			10, 10,
			ApplicationManager::applicationW - 20, ApplicationManager::applicationH - 20,
			0, 0, 0, 0
		);
		Holder& mainHolder = mainView->getHolders().getElement("MAIN_HOLDER");

		mainHolder.createButton(
			"BACK_BUTTON", "Back",
			[]() { ApplicationManager::application.getWindow()->setCurrentView(ApplicationManager::application.getWindow()->getViews().getElement("MAIN_VIEW")); },
			true, false,
			mainHolder.getX(), mainHolder.getY(),
			mainHolder.getW() / 8, mainHolder.getH() / 15,
			"mid", "mid", 255, 255, 255, 127
		);

		mainHolder.createTextBox(
			"TITLE", "Biberons",
			true, true,
			(mainHolder.getX() + mainHolder.getW()) / 4, (mainHolder.getX() + mainHolder.getW()) / 20,
			mainHolder.getW() / 2, mainHolder.getH() / 10,
			"mid", "mid", 255, 255, 255, 63
		);

		mainView->createHolder(
			"TEMPLATE_FEEDER_HOLDER", true,
			mainHolder.getX() + 5, mainHolder.getY() + mainHolder.getH() / 6,
			mainHolder.getW() - 10, mainHolder.getH() / 10,
			0, 0, 0, 0
		);
		Holder& feederHolder = mainView->getHolders().getElement("TEMPLATE_FEEDER_HOLDER");

		for (auto i = 0; i < ApplicationManager::application.getFeeders().getLen(); i++)
		{
			mainView->createHolder(
				"FEEDER_HOLDER_" + i, true,
				feederHolder.getX(), feederHolder.getY() * (i + 1),
				feederHolder.getW(), feederHolder.getH(),
				0, 0, 0, 127
			);

			cout << (feederHolder.getY() + feederHolder.getH() + 10) * i << endl;
		}

		/*for (auto i = 0; i < ApplicationManager::application.getFeeders().getLen(); i++)
		{
			bool isActive = false;
			if (i == 0) isActive = true;

			mainView->createHolder(
				to_string(i).c_str(), isActive,
				feederHolder.getX(), feederHolder.getY() + (feederHolder.getH() + 10) * i,
				feederHolder.getW(), feederHolder.getH(),
				0, 0, 0, 127
			);
			Holder& feederHolder_ = mainView->getHolders().getElement(to_string(i).c_str());

			feederHolder_.createTextBox(
				"TITLE", to_string(i + 1).c_str(),
				true, true,
				feederHolder_.getX() + 2, feederHolder_.getY() + 2,
				feederHolder_.getW() / 10 - 4, feederHolder_.getH() - 4,
				"mid", "mid", 255, 255, 255, 63
			);
			TextBox* feederTitle = feederHolder_.getTextBoxs().getElement("TITLE");

			feederHolder_.createHolder(
				"FEEDER_CONTENT_HOLDER", true,
				feederTitle->getX() + feederTitle->getW() + 4, feederTitle->getY(),
				feederTitle->getX() + feederHolder.getW() - (feederTitle->getX() + feederTitle->getW() + 8), feederHolder.getH() - 4,
				255, 0, 0, 127
			);
			Holder& feederContentHolder = feederHolder_.getHolders().getElement("FEEDER_CONTENT_HOLDER");

			feederContentHolder.createButton(
				"G_", "<-",
				[i]() {
					int i_ = i;
					if (i_ <= 0) i_ = ApplicationManager::application.getFeeders().getLen() - 1;
					const char* temp_ = to_string(i).c_str();
					ApplicationManager::application.getWindow()->getCurrentView()->getHolders().getElement("MAIN_HOLDER").getHolders().getElement(temp_).setActive(true);
					ApplicationManager::application.getWindow()->getCurrentView()->getHolders().getElement("MAIN_HOLDER").getHolders().getElement(temp_).setActive(false);
				},
				true, true,
					feederContentHolder.getX(), feederContentHolder.getY(),
					feederContentHolder.getW() / 10, feederContentHolder.getH(),
					"mid", "mid", 255, 255, 255, 127
					);

			feederContentHolder.createButton(
				"D_", "->",
				[i]() {
					int i_ = i;
					if (i_ >= ApplicationManager::application.getFeeders().getLen() - 1) i_ = 0;
					const char* temp_ = to_string(i).c_str();
					ApplicationManager::application.getWindow()->getCurrentView()->getHolders().getElement("MAIN_HOLDER").getHolders().getElement(temp_).setActive(true);
					ApplicationManager::application.getWindow()->getCurrentView()->getHolders().getElement("MAIN_HOLDER").getHolders().getElement(temp_).setActive(false);
				},
				true, true,
					feederContentHolder.getX() + feederContentHolder.getW() - feederContentHolder.getW() / 10, feederContentHolder.getY(),
					feederContentHolder.getW() / 10, feederContentHolder.getH(),
					"mid", "mid", 255, 255, 255, 127
					);
		}*/

		mainHolder.createButton(
			"ADD_BUTTON", "Ajouter un biberon",
			[]() { ApplicationManager::application.getWindow()->setCurrentView(ApplicationManager::application.getWindow()->getViews().getElement("ADD_FEEDER_VIEW")); },
			true, false,
			(mainHolder.getX() + mainHolder.getW()) / 4, (mainHolder.getY() + mainHolder.getH()) / 1.2,
			mainHolder.getW() / 2, mainHolder.getH() / 10,
			"mid", "mid", 255, 255, 255, 127
		);
	}
	{ // ADD_FEEDER_VIEW
		window->createView("ADD_FEEDER_VIEW", false);
		View* mainView = window->getViews().getElement("ADD_FEEDER_VIEW");

		mainView->createHolder(
			"MAIN_HOLDER", true,
			10, 10,
			ApplicationManager::applicationW - 20, ApplicationManager::applicationH - 20,
			0, 0, 0, 0
		);
		Holder& mainHolder = mainView->getHolders().getElement("MAIN_HOLDER");

		mainHolder.createButton(
			"BACK_BUTTON", "Back",
			[]() { ApplicationManager::application.getWindow()->setCurrentView(ApplicationManager::application.getWindow()->getViews().getElement("FEEDER_VIEW")); },
			true, false,
			mainHolder.getX(), mainHolder.getY(),
			mainHolder.getW() / 8, mainHolder.getH() / 15,
			"mid", "mid", 255, 255, 255, 127
		);

		mainHolder.createTextBox(
			"TITLE", "+ Biberon",
			true, true,
			(mainHolder.getX() + mainHolder.getW()) / 4, (mainHolder.getX() + mainHolder.getW()) / 20,
			mainHolder.getW() / 2, mainHolder.getH() / 10,
			"mid", "mid", 255, 255, 255, 63
		);

		mainHolder.createTextBox(
			"QUANTITY", "Quantité",
			true, false,
			(mainHolder.getX() + mainHolder.getW()) / 4, (mainHolder.getX() + mainHolder.getW()) / 2,
			mainHolder.getW() / 2, mainHolder.getH() / 16,
			"mid", "mid", 255, 255, 255, 63
		);
		TextBox* quantityTB = mainHolder.getTextBoxs().getElement("QUANTITY");

		mainHolder.createInputBox(
			"QUANTITY", true, "250", true, false,
			quantityTB->getX(), quantityTB->getY() + quantityTB->getH(),
			mainHolder.getW() / 2, mainHolder.getH() / 14
		);
		InputBox* quantityIB = mainHolder.getInputBoxes().getElement("QUANTITY");

		mainHolder.createTextBox(
			"HOUR", "Timestamp voulu :d",
			true, false,
			(mainHolder.getX() + mainHolder.getW()) / 4, (mainHolder.getX() + mainHolder.getW()) / 1.5,
			mainHolder.getW() / 2, mainHolder.getH() / 16,
			"mid", "mid", 255, 255, 255, 63
		);
		TextBox* hourTB = mainHolder.getTextBoxs().getElement("HOUR");

		mainHolder.createInputBox(
			"HOUR", true, to_string(time(0)).c_str(), true, false,
			hourTB->getX(), hourTB->getY() + hourTB->getH(),
			mainHolder.getW() / 2, mainHolder.getH() / 14
		);
		InputBox* hourIB = mainHolder.getInputBoxes().getElement("HOUR");

		mainHolder.createButton(
			"ADD_BUTTON", "Ajouter un biberon",
			[]() { ApplicationManager::application.createFeeder(
				stoi(ApplicationManager::application.getWindow()->getCurrentView()->getHolders().getElement("MAIN_HOLDER").getInputBoxes().getElement("HOUR")->text),
				stoi(ApplicationManager::application.getWindow()->getCurrentView()->getHolders().getElement("MAIN_HOLDER").getInputBoxes().getElement("QUANTITY")->text));
		ApplicationManager::application.getWindow()->setCurrentView(ApplicationManager::application.getWindow()->getViews().getElement("FEEDER_VIEW"));
			},
			true, false,
				(mainHolder.getX() + mainHolder.getW()) / 4, (mainHolder.getY() + mainHolder.getH()) / 1.2,
				mainHolder.getW() / 2, mainHolder.getH() / 10,
				"mid", "mid", 255, 255, 255, 127
				);
	}
	{ // STOCK_VIEW
		window->createView("STOCK_VIEW", false);
		View* mainView = window->getViews().getElement("STOCK_VIEW");

		mainView->createHolder(
			"MAIN_HOLDER", true,
			10, 10,
			ApplicationManager::applicationW - 20, ApplicationManager::applicationH - 20,
			0, 0, 0, 0
		);
		Holder& mainHolder = mainView->getHolders().getElement("MAIN_HOLDER");

		mainHolder.createButton(
			"BACK_BUTTON", "Back",
			[]() { ApplicationManager::application.getWindow()->setCurrentView(ApplicationManager::application.getWindow()->getViews().getElement("MAIN_VIEW")); },
			true, false,
			mainHolder.getX(), mainHolder.getY(),
			mainHolder.getW() / 8, mainHolder.getH() / 15,
			"mid", "mid", 255, 255, 255, 127
		);
	}
	/*{
		ApplicationManager::application.getWindow()->createView("MAIN", true);
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
	/*{
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
	}*/

	/*ApplicationManager::application.stock.createProduct("test", 12);
	cout << ApplicationManager::application.stock.getProducts().getElement("test")->getName() << endl;
	ApplicationManager::application.stock.modifyProduct("test", "otherTest", 12);
	cout << ApplicationManager::application.stock.getProducts().getElement("otherTest")->getName() << endl;*/

	/*if (SDL_Init(SDL_INIT_VIDEO) < 0)return -1;

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
	}*/

	//Mix_PlayMusic(ApplicationManager::application.getWindow()->EEG, -1);

	while (ApplicationManager::application.isRunning())
	{
		unsigned int frame_limit = SDL_GetTicks() + FPSLimit;
		Utils::SDL_Limit_FPS(frame_limit, FPSLimit);

		ApplicationManager::application.handleEvents();
		ApplicationManager::application.update();
		ApplicationManager::application.render();
	}

	//Mix_FreeMusic(ApplicationManager::application.getWindow()->EEG);

	ApplicationManager::application.clean();

	return 0;
}