#include "Stock.h"

Stock::Stock()
{
}

Stock::~Stock()
{
}

/*###### Product ######*/
Container<Product*>& Stock::getProducts()
{
	return this->productList;
}

void Stock::createProduct(const char* name, int quantity)
{
	this->productList.add(name, new Product(name, quantity));
}
/*###### Product ######*/

void Stock::modifyProduct(const char* name, const char* newName, int quantity)
{
	this->productList.remove(name);
	this->createProduct(newName, quantity);
}

void Stock::deleteProduct(const char* name)
{
	// TODO VERIF
	this->productList.remove(name);
}
