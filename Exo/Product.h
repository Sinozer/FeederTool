#pragma once

#include <iostream>
using namespace std;

class Product
{
protected:
	time_t timeCreated;

	const char* name;
	int quantity;

public:
	Product();
	Product(const char* name = "New product", int quantity = 1);
	~Product();

	void setName(const char* newName);
	const char* getName();

	void setQuantity(int quantity);
	int getQuantity();
};