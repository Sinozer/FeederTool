#pragma once

#include <fstream>
#include <json.hpp>
using json = nlohmann::json;

class DataManager
{
protected:
public:
	void static addFeeder(const char* number, int timeC, int timeT, int quantity, bool eat, bool vomited);
	void static addProduct(const char* name, int time, int quantity);
	void static modifyFeeder(const char* number, int timeC, int timeT, int quantity, bool eat, bool vomited);
	void static modifyProduct(const char* name, int time, int quantity);

	//void static modifyFeeder();

	json static getFeeders();
	json static getProducts();
	json static getAll();
	json static templateFeeder(int timeC, int timeT, int quantity, bool eat, bool vomited);
	json static templateProduct(int time, int quantity);
	void static newDay();
};