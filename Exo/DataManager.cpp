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
		{"1",
			{
				{"timeCreated", 1},
				{"isEated", true}
			}
		},
		{"2",
			{
				{"timeCreated", 17368428},
				{"isEated", true}
			}
		}
	}
  },
  {"stocks",
	{
		{"milk",
			{
				{"quantity", 10}
			}
		}
	}
  }
};

json DataManager::templateFeeder(int time, bool eat)
{
	json tempFeeder =
	{
		{"timeCreated", time},
		{"isEated", eat}
	};
	return tempFeeder;
}

json DataManager::templateProduct(int time, bool eat)
{
	json tempFeeder =
	{
		{"timeCreated", time},
		{"isEated", eat}
	};
	return tempFeeder;
}





void DataManager::setCategory()
{

}


void DataManager::addFeeder(const char* number, int time, bool eat)
{
	json feeders = DataManager::getFeeders();
	feeders[number] = DataManager::templateFeeder(time, eat);

	json all = DataManager::getAll();
	all["feeders"] = feeders;
	//[number] = DataManager::templateFeeder(time, eat)

	//cout << all << endl;

	ofstream o("data.json");
	o << setw(10) << all << endl;
}

void DataManager::addProduct()
{

}


json DataManager::getFeeders()
{
	return DataManager::getAll()["feeders"];
}

json DataManager::getProducts()
{
	return DataManager::getAll()["stocks"];
}

json DataManager::getAll()
{
	ifstream file("data.json");
	json reader = json::parse(file);

	return reader;
}