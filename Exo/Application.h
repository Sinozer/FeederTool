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

	void handleEvents(); //trigger on SDL event
	void update(); //updated place Holder
	void render(); //print SDL window
	void clean(); //clear the SDL window


	/*###### MainSDLWindow ######*/
	MainSDLWindow* getWindow(); //return SDL window
	/*###### MainSDLWindow ######*/

	/*###### Feeder ######*/
	Container<Feeder>& getFeeders(); // return the list of Feeders
	void createFeeder(const char* name,
		time_t timeToTake, int quantity = 0,
		bool eated = false, bool vomited = false);
	/*###### Feeder ######*/
};