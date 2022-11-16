#pragma once

#include <fstream>
#include <json.hpp>
using json = nlohmann::json;

class DataManager
{
protected:
public:
	void static setCategory();

	void static addFeeder(const char* number, int time, bool eat);
	void static addProduct();

	//void static modifyFeeder();

	json static getFeeders();
	json static getProducts();
	json static getAll();
	json static templateFeeder(int time, bool eat);
	json static templateProduct(int time, bool eat);
};