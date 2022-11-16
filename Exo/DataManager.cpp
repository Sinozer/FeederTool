#include "DataManager.h"

#include <iostream>
#include <iomanip>

using namespace std;

// for convenience
using json = nlohmann::json;


json stocks =
{
  {"feeders",
	{

	}
},
  {"stock",
	{
		{"milk",
			{
				{"timeCreated", 1}, //time_t
				{"quantity", 10}, //int
			}
		}
	}
  }
};

json DataManager::templateFeeder(int timeC, int timeT, int quantity, bool eat, bool vomited)
{
	json tempFeeder =
	{
		{"timeCreated", timeC}, //time_t
		{"timeTaken", timeT}, //time_t
		{"quantity", quantity}, //int
		{"isEated", eat},
		{"isVomited", vomited} //bool
	};
	return tempFeeder;
}

json DataManager::templateProduct(int time, int quantity)
{
	json tempProduct =
	{
		{"timeCreated", time}, //time_t
		{"quantity", quantity}, //int
	};
	return tempProduct;
}

void DataManager::newDay()
{
	json all = DataManager::getAll();
	all["feeders"] = {};

	ofstream o("data.json");
	o << setw(10) << all << endl;
}


void DataManager::addFeeder(const char* number, int timeC, int timeT, int quantity, bool eat, bool vomited)
{
	json feeders = DataManager::getFeeders();
	if (feeders.size() == 0 || feeders[number] == NULL)
	{
		feeders[number] = DataManager::templateFeeder(timeC, timeT, quantity, eat, vomited);

		json all = DataManager::getAll();
		all["feeders"] = feeders;
		ofstream o("data.json");
		o << setw(10) << all << endl;
	}	
}

void DataManager::addProduct(const char* name, int time, int quantity)
{
	json products = DataManager::getProducts();
	if (products[name] != NULL)
		return;
	products[name] = DataManager::templateProduct(time, quantity);

	json all = DataManager::getAll();
	all["stock"] = products;

	ofstream o("data.json");
	o << setw(10) << all << endl;
}

void DataManager::modifyFeeder(const char* number, int timeC, int timeT, int quantity, bool eat, bool vomited)
{
	json feeders = DataManager::getFeeders();
	if (feeders[number].size() == 0 )return;
	feeders[number] = DataManager::templateFeeder(timeC, timeT, quantity, eat, vomited);

	json all = DataManager::getAll();
	all["feeders"] = feeders;
	ofstream o("data.json");
	o << setw(10) << all << endl;
}

void DataManager::modifyProduct(const char* name, int time, int quantity)
{
	json products = DataManager::getProducts();
	if (products[name].size() == 0 )return;
	products[name] = DataManager::templateProduct(time, quantity);

	json all = DataManager::getAll();
	all["stock"] = products;

	ofstream o("data.json");
	o << setw(10) << all << endl;
}


json DataManager::getFeeders()
{
	return DataManager::getAll()["feeders"];
}

json DataManager::getProducts()
{
	return DataManager::getAll()["stock"];
}

json DataManager::getAll()
{
	ifstream file("data.json");
	json reader = json::parse(file);

	return reader;
}