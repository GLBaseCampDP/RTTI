// REINTERPRET_CAST.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
int main()
{
	int i;
	int *p = &i;
	cout << "&i - "  <<	p << endl;
	// Приведення вказівника до цілого числа
	i = reinterpret_cast<int> (p);
	cout << " i " << i
		<< endl;
	cout << "HEX i 	" << hex << i << endl;
		return 0;
}

