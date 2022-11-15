#pragma once

#include "Container.h"

#include "Product.h"


class Stock
{
protected:
	time_t timeCreated;			// When application instance is created

	Container<Product> productList;

public:
	Stock();
	~Stock();
};