#pragma once

#include "Container.h"

#include "Product.h"


class Stock
{
protected:
	Container<Product*> productList;

public:
	Stock();		//Create Stock
	~Stock();

	/*###### Product ######*/
	Container<Product*>& getProducts(); //return the list of Product
	/*###### Product ######*/
	void createProduct(const char* name, int quantity);
	void modifyProduct(const char* name, const char* newName, int quantity);
	void deleteProduct(const char* name);
};