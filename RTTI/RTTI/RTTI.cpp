// RTTI.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream> 
#include <typeinfo> 
using namespace std;
struct BaseClass {
	virtual void f() {}; // ����� BaseClass ��� ����������
};
struct Derivedl : public BaseClass {
	virtual void f() {}; // ������������� ����������
};
struct  Derived2 : public BaseClass {
	virtual void f() {}; // ������������� ����������
};
int main() {
	int i;
	BaseClass *p, b; Derivedl o1; Derived2 o2;
	// ���� �� ����� ���������� ��� ���������� ���
	cout << "����� ����� i � "; cout << typeid(i).name() << endl;
	// ��������� �����������
	p = &b;
	cout << "��������  � ����� �� �ᒺ�� ���� ";
		cout << typeid (*p).name() << endl;
	p = &o1;
	cout << "��������  � ����� �� �ᒺ�� ���� ";
		cout << typeid(*p).name() << endl;
	p = &o2;
	cout << "��������  � ����� �� �ᒺ�� ���� ";
		cout << typeid(*p).name() << endl;
	return 0;
}



