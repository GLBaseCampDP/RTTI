// RTTI.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream> 
#include <typeinfo> 
using namespace std;
struct BaseClass {
	virtual void f() {}; // класс BaseClass стає поліморфним
};
struct Derivedl : public BaseClass {
	virtual void f() {}; // реалізовувється поліморфізм
};
struct  Derived2 : public BaseClass {
	virtual void f() {}; // реалізовувється поліморфізм
};
int main() {
	int i;
	BaseClass *p, b; Derivedl o1; Derived2 o2;
	// Вивід на екран інформації про вбудований тип
	cout << "Типом змінної i є "; cout << typeid(i).name() << endl;
	// Реалізація поліморфізму
	p = &b;
	cout << "Вказівник  р вказує на об’єкт типу ";
		cout << typeid (*p).name() << endl;
	p = &o1;
	cout << "Вказівник  р вказує на об’єкт типу ";
		cout << typeid(*p).name() << endl;
	p = &o2;
	cout << "Вказівник  р вказує на об’єкт типу ";
		cout << typeid(*p).name() << endl;
	return 0;
}



