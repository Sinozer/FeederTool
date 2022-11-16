#include "DataManager.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <json.hpp>

using namespace std;

// for convenience
using json = nlohmann::json;


DataManager::DataManager()
{

json stocks = {
  {"milk", 10},
  {"test", 1},
};


	//read json
	//ifstream f("test.json");
	//json data = json::parse(f);
}

DataManager::~DataManager()
{

}




