#pragma once

#include <fstream>
#include <json.hpp>
using json = nlohmann::json;

class DataManager
{
//protected:
//	string category;
public:
	void static setCategory();

	void static addFeeder();
	void static addProduct();

	void static modifyFeeder();

	json static getFeeders();
	json static getProducts();
};