#pragma once

#include <iostream>
#include <json.hpp>
#include <fstream>
#include <iomanip>

using json = nlohmann::json;

class DataManager
{
protected:
public:
	void static newDay();

	void static addFeeder(int number, int timeC, int timeT, int quantity, bool eat, bool vomited);
	void static modifyFeeder(int number, int timeC, int timeT, int quantity, bool eat, bool vomited);
	void static removeFeeder(int number);

	void static addProduct(const char* name, int quantity);
	void static modifyProduct(const char* name, int quantity);
	void static removeProduct(const char* name);

	//void static modifyFeeder();

	json static getFeeders();
	json static getProducts();
	json static getAll();
	json static templateFeeder(int timeC, int timeT, int quantity, bool eat, bool vomited);
	json static templateProduct(int quantity);
};