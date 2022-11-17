#include "Stock.h"

Stock::Stock()
{
}

Stock::~Stock()
{
}

Container<Product>& Stock::getProduct()
{
	return this->productList;
}

void Stock::createProduct(const char* name, int quantity)
{
	Product* addProduct = new Product();
	this->productList.add(name, *addProduct);
	addProduct->createProduct(quantity);
}

void Stock::modifyProduct(const char* name, int quantity)
{

}

void Stock::deleteProduct(const char* name)
{
	this->productList.remove(name);
}
