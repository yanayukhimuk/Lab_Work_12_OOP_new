#pragma once
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std; 
class MyVector
{
public:
    explicit MyVector(size_t num = 0) //�������� �� ����� 
        : vector_size(num), vector_data(new int[vector_size])
    {
        log("�����������");
    }

    ~MyVector()
    {
        log("����������");
        if (vector_data) {
            delete[] vector_data;
            vector_data = 0;
        }
    }

    MyVector(const MyVector& other)
        : vector_size(other.vector_size), vector_data(new int[vector_size])
    {
        log("����������� �����������");
        for (size_t i = 0; i < vector_size; ++i)
            vector_data[i] = other.vector_data[i]; // �������� ������ ������ ������� � ������ 
    }

    MyVector& operator=(const MyVector& other)
    {
        log("�������� �����������");
        MyVector tmp(other); // ��������� ������ 
        std::swap(vector_size, tmp.vector_size);
        std::swap(vector_data, tmp.vector_data);
        return *this;
    }
private:
    void log(const char* msg)
    {
        cout << "[" << this << "] " << msg << "\n";
    }

    size_t vector_size;
    int* vector_data;
};


