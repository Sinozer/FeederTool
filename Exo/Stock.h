#pragma once

#include "Container.h"

#include "Product.h"


class Stock
{
protected:
	Container<Product*> productList;

public:
	Stock();
	~Stock();

	/*###### Product ######*/
	Container<Product*>& getProducts();
	void createProduct(const char* name, int quantity);
	/*###### Product ######*/
	void modifyProduct(const char* name, const char* newName, int quantity);
	void deleteProduct(const char* name);
};