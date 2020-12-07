#pragma once
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// ����� ����������� 


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
		cout << "����������" << endl;
		delete[] data;
	}

	string(const string& that) // ���� �������� ����������� �� ����� ����������� ���� string
	{
		cout << "����������� �����������" << endl;
		size_t size = strlen(that.data) + 1;
		data = new char[size];
		memcpy(data, that.data, size);
	}
	string(string&& that)
	{
		cout << "����������� �����������" << endl;
		data = that.data;
		that.data = nullptr;
	}
	string& operator = (string that)
	{
		swap(data, that.data); // that ����� ��������������� � ����������� �� ����, �������� �� �������� ��� ��������� ������������ ��������� lvalue ��� rvalue 
		return*this;
	}
};