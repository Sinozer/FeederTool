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
		bool eated = false, bool vomited = false,
		time_t timeCreated = time(0));
	~Feeder();

	void setTimeTaken(time_t timeTaken); //register when the feeder is eat by the baby
	time_t getTimeTaken(); //return the time when the feeder is eat

	void setQuantity(int quantity);
	int getQuantity();

	void setEated(bool eated);
	bool isEated(); // return true or false is the feeder is eated

	void setVomited(bool vomited);
	bool isVomited();	// return true or false is the feeder is vomited

	void debug();
};