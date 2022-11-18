#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>

#include <json.hpp>

using json = nlohmann::json;

class DataManager
{
protected:
public:
	void static newDay(); //refresh the data on new day

	void static addFeeder(int number, int timeC, int timeT, int quantity, bool eat, bool vomited);
	void static modifyFeeder(int number, int timeC, int timeT, int quantity, bool eat, bool vomited);
	void static removeFeeder(int number);

	void static addProduct(const char* name, int quantity);
	void static modifyProduct(const char* name, int quantity);
	void static removeProduct(const char* name);

	json static getFeeders(); //return Feeder
	json static getProducts(); //return Product
	json static getAll(); //retun all data
	json static templateFeeder(int timeC, int timeT, int quantity, bool eat, bool vomited); //data template of feeder
	json static templateProduct(int quantity); //data tamplate of product
};