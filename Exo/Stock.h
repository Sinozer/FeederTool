#pragma once

#include "Container.h"

#include "Product.h"


class Stock
{
protected:
	Container<Product> productList;

public:
	Stock();
	~Stock();

	Container<Product>& getProduct();
	void createProduct(const char* name, int quantity);
	void modifyProduct(const char* name, int quantity);
	void deleteProduct(const char* name);
};