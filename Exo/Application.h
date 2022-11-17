#pragma once

#include "Container.h"

#include "MainSDLWindow.h"
#include "Feeder.h"
#include "Stock.h"

class Application
{
protected:
	time_t timeCreated;			// When application instance is created
	bool running;


	/*###### MainSDLWindow ######*/
	MainSDLWindow* window;
	/*###### MainSDLWindow ######*/

	/*###### Feeder ######*/
	Container<Feeder> feederList;		// List of all differents feeders
	/*###### Feeder ######*/


public:
	/*###### Cart ######*/
	Stock stock;
	/*###### Cart ######*/
	int mouseX, mouseY; // TODO GET SET
	bool lClick, backSpace, bReturn; // TODO GET SET

	string both = "";
	string letters = "";
	string numbers = "";

	Application();											// Create application
	~Application();

	bool isRunning();

	void handleEvents();
	void update();
	void render();
	void clean();


	/*###### MainSDLWindow ######*/
	MainSDLWindow* getWindow();
	/*###### MainSDLWindow ######*/

	/*###### Feeder ######*/
	Container<Feeder>& getFeeders();
	void createFeeder(const char* name,
		time_t timeToTake, int quantity = 0,
		bool eated = false, bool vomited = false);
	/*###### Feeder ######*/
};