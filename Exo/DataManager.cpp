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
				{"isEated", false}
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



void DataManager::setCategory()
{
	ofstream o("data.json");
	o << setw(4) << stocks << endl;
}

void DataManager::addFeeder()
{

}

void DataManager::addProduct()
{

}


json DataManager::getFeeders()
{
	ifstream f("data.json");
	json data = json::parse(f);

	return data["feeder"];
}

json DataManager::getProducts()
{
	ifstream f("data.json");
	json data = json::parse(f);

	return data["stock"];
}





