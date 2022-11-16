#pragma once

#include <fstream>
#include <json.hpp>
using json = nlohmann::json;

class DataManager
{
protected:
public:
	void static setCategory();

	void static addFeeder();
	void static addProduct();

	//void static modifyFeeder();

	json static getFeeders();
	json static getProducts();
	json static getAll();
	json static templateFeeder(const char* number, int time, bool eat);
};