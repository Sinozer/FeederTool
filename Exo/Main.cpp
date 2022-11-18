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

		//bool isActive = true;

		for (auto i = 0; i < ApplicationManager::application.getFeeders().getLen(); i++)
		{
			//if (i != 0) isActive = false;
			mainView->createHolder(
				"FEEDER_HOLDER_" + i, true,
				feederHolder.getX(), feederHolder.getY() * (i + 1),
				feederHolder.getW(), feederHolder.getH(),
				0, 0, 0, 127
			);
			Holder& feederHolder_ = mainView->getHolders().getElement("FEEDER_HOLDER_" + i);

			feederHolder_.createTextBox(
				"TITLE", to_string(i + 1).c_str(),
				true, true,
				feederHolder_.getX() + 2, feederHolder_.getY() + 2,
				feederHolder_.getW() / 10 - 4, feederHolder_.getH() - 4,
				"mid", "mid", 255, 255, 255, 63
			);

			/*feederHolder_.createTextBox(
				"QUANTITY", "Quantité",
				true, false,
				feederHolder_.getX() + feederHolder_.getW() / 4 + 2, feederHolder_.getY() + feederHolder_.getH() / 10 + 2,
				feederHolder_.getW() / 2, feederHolder_.getH() / 16,
				"mid", "mid", 255, 255, 255, 63
			);
			TextBox* quantityTB = feederHolder_.getTextBoxs().getElement("QUANTITY");

			feederHolder_.createInputBox(
				"QUANTITY", true, "250", true, false,
				quantityTB->getX(), quantityTB->getY() + quantityTB->getH(),
				feederHolder_.getW() / 2, feederHolder_.getH() / 16
			);
			InputBox* quantityIB = mainHolder.getInputBoxes().getElement("QUANTITY");*/
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

	//Mix_PlayMusic(ApplicationManager::application.getWindow()->EEG, 1);

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