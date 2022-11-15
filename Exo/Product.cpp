#include "Product.h"

Product::Product()
{
	this->timeCreated = time(0);
	this->id = NULL;
	this->name = NULL;
	this->quantity = NULL;
}

Product::Product(int id, const char* name, int quantity)
{
	this->timeCreated = time(0);
	this->id = id;
	this->name = name;
	this->quantity = quantity;
}

Product::~Product()
{
}

void Product::setId(int id)
{
	this->id = id;
}

int Product::getId()
{
	return this->id;
}

void Product::setName(const char* newName)
{
	this->name = newName;
}

const char* Product::getName()
{
	return this->name;
}

void Product::setQuantity(int quantity)
{
	this->quantity = quantity;
}

int Product::getQuantity()
{
	return this->quantity;
}