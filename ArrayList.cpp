#include "ArrayList.h"
#include <iostream>
#include <string>
using namespace std;


bool ArrayList::isEmpty()
{
	for(int i=0;i<size1;i++)
	{
		if(storage[i] != "")
		{
			return false;
		}
	}
	return true;
}

int ArrayList::size()
{
	return size1;
}


bool ArrayList::add(string value)
{
	insert(value, size1);
	return true;
}

string ArrayList::get(int atIndex)
{
	for(int i=0; i<size1; i++)
	{
		if (i == atIndex)
		{
			return storage[i];
		}
	}

	return "";
}

bool ArrayList::insert(string value, int atIndex)
{
	if(atIndex>size1)
	{
		return false;
	}
	else
	{
		if(size1==capacity)
		{
			int newCapacity=capacity*2;
			string* biggerStorage=new string[newCapacity];
			for(int i=0; i<size1; i++)
			{
				biggerStorage[i]=storage[i];
			}
			delete[] storage;
			storage = biggerStorage;
			capacity=newCapacity;
		}
		for(int i=size1-1; i>=atIndex; i--)
		{
			storage[i+1]=storage[i];
		}

		storage[atIndex]=value;
		size1=size1 + 1;
		return true;
	}
}

string ArrayList::remove(int atIndex)
{
	if(atIndex>=size1 || atIndex<0 || size1<1)
	{
		return"";
	}
	else
	{
		string save = storage[atIndex];
		for(int i=atIndex; i<size1; i++)
		{
			storage[i] = storage[i+1];
		}
		size1 = size1 - 1;
		return save;
	}
}

void ArrayList::clear()
{
	size1=0;
	for (int i=0; i<size1; i++)
	{
		storage[i] = "";
	}
}

string ArrayList::set(int atIndex, string value)
{   string temporary="";
if(atIndex<size1)
{
	temporary = storage[atIndex];
	storage[atIndex]=value;
	return temporary;
}
else
{
	return "";
}
}

bool ArrayList::contains(string value)
{
	for(int i=0; i<size1; i++)
	{
		if(storage[i] == value)
		{
			return true;
		}
	}
	return false;
}

bool ArrayList::remove(string value)
{
	for(int i=0; i<size1; i++)
	{
		if(storage[i] == value)
		{
			for(int j=i; j<size1; j++)
			{
				storage[j]=storage[j+1];
			}
			size1 = size1 - 1;
		}
		return true;
	}
	return false;
}

int ArrayList::indexOf(string value)
{
	for(int i=0; i<size1; i++)
	{
		if(storage[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int ArrayList::lastIndexOf(string value)
{
	for(int i=size1; i>0; i--)
	{
		if (storage[i] == value)
		{
			return i;
		}
	}
	return -1;
}
