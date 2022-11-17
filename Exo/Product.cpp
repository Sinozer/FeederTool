#include "Product.h"

Product::Product()
{
	this->name = NULL;
	this->quantity = NULL;
}

//Product::Product(const char* name, int quantity)
//{
//	this->timeCreated = time(0);
//	this->name = name;
//	this->quantity = quantity;
//}

Product::~Product()
{
}

void Product::createProduct(int quantity)
{
	this->name = name;
	this->quantity = quantity;
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