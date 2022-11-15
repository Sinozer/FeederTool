#pragma once

#include <unordered_map>
using namespace std;

#include "Utils.h"

template <typename T>
class Container
{
protected:
public:
	Container();
	~Container();

	unordered_map<const char*, T> list;

	T& getElement(const char* name);
	size_t getLen();

	void add(const char* name, T object);
	int remove(const char* name);		
};

template <typename T>
inline
Container<T>::Container()
{
}

template <typename T>
inline
Container<T>::~Container()
{
}

template <typename T>
inline
size_t Container<T>::getLen()
{
	return this->list.size();
}

template <typename T>
inline
T& Container<T>::getElement(const char* name)
{
	return this->list[name];
}

template <typename T>
inline
void Container<T>::add(const char* name, T object)
{
	this->list[name] = object;
}

template <typename T>
inline
int Container<T>::remove(const char* name)
{
	if (this->list.find(name) == this->list.end()) return 1;
	else
	{
		this->list.erase(name);
		return 0;
	}
}