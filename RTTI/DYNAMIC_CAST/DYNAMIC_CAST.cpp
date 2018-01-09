// DYNAMIC_CAST.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <typeinfo.h>
using namespace std;

using namespace std;
struct A {
	// Для коректної роботи механізму RTTI 
	// базовий клас повине бути поліморфним
	virtual void f(void) { cout << "A"; }
};
struct B : public A {
	// реалізація поліморфізму
	virtual void f(void) { cout << "B"; }
};
int main(void) {
	int mm;
	try 	{
		B d, *pd;
		A *b1 = &d;
		//  Base1 *b1 = new B;
		// Дозволене приведення з Base1 у Derived.
		if ((pd = dynamic_cast<B*>(b1)) != 0) 	{
			cout << " Cast result is - " << typeid(pd).name() << endl;
			pd->f();
		}
		else
			throw bad_cast();
	}
	catch (bad_cast) {
		cout << "Error of dynamic_cast" << endl;
		return 1;
	}
	catch (...)	{
		cout << "Generic error" << endl;
		return 1;
	}
	system("pause");
	return 0;
}

