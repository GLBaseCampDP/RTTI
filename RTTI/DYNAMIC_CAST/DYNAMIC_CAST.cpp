// DYNAMIC_CAST.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#include <typeinfo.h>
using namespace std;

using namespace std;
struct A {
	// ��� �������� ������ �������� RTTI 
	// ������� ���� ������ ���� ����������
	virtual void f(void) { cout << "A"; }
};
struct B : public A {
	// ��������� �����������
	virtual void f(void) { cout << "B"; }
};
int main(void) {
	int mm;
	try 	{
		B d, *pd;
		A *b1 = &d;
		//  Base1 *b1 = new B;
		// ��������� ���������� � Base1 � Derived.
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

