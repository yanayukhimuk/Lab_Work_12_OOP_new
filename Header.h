#pragma once
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// потом рассмотреть 


class string
{
	char* data;
public:
	string(const char* p)
	{
		size_t size = strlen(p) + 1;
		data = new char[size];
		memcpy(data, p, size);
	}
	~string()
	{
		cout << "Деструктор" << endl;
		delete[] data;
	}

	string(const string& that) // этот параметр связывается со всеми выражениями типа string
	{
		cout << "Конструктор копирования" << endl;
		size_t size = strlen(that.data) + 1;
		data = new char[size];
		memcpy(data, that.data, size);
	}
	string(string&& that)
	{
		cout << "Конструктор перемещения" << endl;
		data = that.data;
		that.data = nullptr;
	}
	string& operator = (string that)
	{
		swap(data, that.data); // that будет инициализирован в зависимости от того, является ли аргумент для оператора присваивания значением lvalue или rvalue 
		return*this;
	}
};