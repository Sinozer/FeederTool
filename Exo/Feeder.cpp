#include "Feeder.h"

Feeder::Feeder()
{
	timeCreated = time(0);

	this->timeTaken = NULL;
	this->quantity = NULL;
	this->eated = NULL;
	this->vomited = NULL;
}

Feeder::Feeder(time_t timeToTake, int quantity, bool eated, bool vomited)
{
	timeCreated = time(0);

	this->timeTaken = timeToTake;
	this->quantity = quantity;
	this->eated = eated;
	this->vomited = vomited;
}

Feeder::~Feeder()
{
}

void Feeder::setTimeTaken(time_t timeTaken)
{
	this->timeTaken = timeTaken;
}
time_t Feeder::getTimeTaken()
{
	return this->timeTaken;
}

void Feeder::setQuantity(int quantity)
{
	this->quantity = quantity;
}
int Feeder::getQuantity()
{
	return this->quantity;
}

void Feeder::setEated(bool eated)
{
	this->eated = eated;
}
bool Feeder::isEated()
{
	return this->eated;
}

void Feeder::setVomited(bool vomited)
{
	this->vomited = vomited;
}
bool Feeder::isVomited()
{
	return this->vomited;
}

void Feeder::debug()
{
	cout << "#####INFOS#####" << endl;
	cout << "timeCreated: " << this->timeCreated << endl;
	cout << "timeTaken: " << this->timeTaken << endl;
	cout << "quantity: " << this->quantity << endl;
	cout << "eated: " << this->eated << endl;
	cout << "vomited: " << this->vomited << endl;
	cout << "#####INFOS#####\n" << endl;
}