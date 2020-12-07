#include "OOP.h"
#include<Windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	MyVector v1(15);
	MyVector v2;
	cout << "Присвоение lvalue...\n";
	v2 = v1;
	cout << "Завершение присвоения lvalue...\n";

	// https://prnt.sc/vxh2a3 - вывод на консоль 
	return 0;
}