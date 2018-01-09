// REINTERPRET_CAST 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
const int sz = 100;
struct X { int a[sz]; };
void print(X* x) {
	for (int i = 0; i < sz; i++)
		cout << x->a[i] << "*";
	cout << endl << "--------------------" << endl;
}
void main()
{
	X x;
	print(&x);
	int* xp = reinterpret_cast<int*>(&x);
	for (int* i = xp; i < xp + sz; i++)
		*i = 0;
	// Вказівник xp можна використовувати як  X*
	// лише після зворотнього перетворення
	print(reinterpret_cast<X*>(xp));
}

