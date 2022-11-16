#include "DataManager.h"

#include <iostream>
#include <iomanip>

using namespace std;

// for convenience
using json = nlohmann::json;


json stocks =
{
  {"feeder",
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
  {"stock",
	{
		{"milk",
			{
				{"quantity", 10}
			}
		}
	}
  }
};

json DataManager::templateFeeder(const char* number, int time, bool eat)
{
	json tempFeeder =
	{
		{number,
			{
				{"timeCreated", time},
				{"isEated", eat}
			}
		},
	};
	return tempFeeder;
}





void DataManager::setCategory()
{

}

void DataManager::addFeeder()
{	
	//json stockFeeder = getFeeders();
	ofstream o("data.json");
	o << setw(10) << templateFeeder("3", 10, false) << endl;

}

void DataManager::addProduct()
{

}


json DataManager::getFeeders()
{
	ifstream file("data.json");
	json reader = json::parse(file);

	return reader["feeder"];
}

json DataManager::getProducts()
{
	ifstream file("data.json");
	json reader = json::parse(file);

	return reader["stock"];
}

json DataManager::getAll()
{
	ifstream file("data.json");
	json reader = json::parse(file);

	return reader;
}







