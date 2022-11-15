#pragma once

#include <iostream>
using namespace std;

class Feeder
{
protected:
	time_t timeCreated;		// When application feeder instance is created

	time_t timeTaken;		// When feeder is taken by baby
	int quantity;			// Which quantity the feeder had
	bool eated;				// Is this feeder already taken
	bool vomited;			// Does the baby vomited the feeder

public:
	Feeder();
	Feeder(time_t timeToTake, int quantity = 0,
		bool eated = false, bool vomited = false);	// Create a feeder base on default values which require changes
	~Feeder();

	void setTimeTaken(time_t timeTaken);
	time_t getTimeTaken();

	void setQuantity(int quantity);
	int getQuantity();

	void setEated(bool eated);
	bool isEated();

	void setVomited(bool vomited);
	bool isVomited();

	void debug();
};