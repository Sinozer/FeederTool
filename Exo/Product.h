#pragma once

#include <iostream>
using namespace std;

class Product
{
protected:

	const char* name;
	int quantity;

public:
	Product();
	Product(const char* name = "New product", int quantity = 1);	//create Product
	~Product();

	void createProduct(int quantity);

	void setName(const char* newName); //define a new name of the product
	const char* getName();

	void setQuantity(int quantity);	//modify a quantity of the product
	int getQuantity();
};