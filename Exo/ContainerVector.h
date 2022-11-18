#pragma once

#include <vector>
using namespace std;

template <typename T> // facilitates the management of vector
class ContainerVector
{
protected:
public:
	ContainerVector();
	~ContainerVector();

	vector<T> list;

	vector<T> getList();
	T& getElement(int id = 0);
	size_t getLen();

	void add(T object);
	int remove(int id);		
};

template <typename T>
inline
ContainerVector<T>::ContainerVector()
{
}

template <typename T>
inline
ContainerVector<T>::~ContainerVector()
{
}

template <typename T>
inline
size_t ContainerVector<T>::getLen()
{
	return this->list.size();
}

template <typename T>
inline
T& ContainerVector<T>::getElement(int id)
{
	if (id > this->getLen() || id < 0) return this->list[0];
	else return this->list[id];
}

template <typename T>
inline
void ContainerVector<T>::add(T object)
{
	this->list.push_back(object);
}

template <typename T>
inline
int ContainerVector<T>::remove(int id)
{
	if (id > this->getLen() || id < 0) return 1;
	else
	{
		this->list.erase(this->list.begin() + id - 1);
		return 0;
	}
}

template <typename T>
inline
vector<T> ContainerVector<T>::getList()
{
	return this->list;
}