// DYNAMIC_CAST 2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#include <typeinfo.h>
using namespace std;
#define  OUT(S) cout << S <<": Cast result is - " << typeid(s).name() << '\n';
#define  VOUT(S) { cout <<"Virtual f call from " << S << '\n'; };
struct A {
	virtual void F() VOUT("AAAAA");
};
struct B : public A {
	void F() VOUT("BBBBB");
};
struct C : public A {
	void F() VOUT("CCCCC");
};

// ������� ��� �������������� ����������
// ���������� ����������� � �� �������
void f1(A* s) {
	OUT("f1");
	//cout << "my: Cast result is pointer on "
	//	<< typeid(s).name() << endl;
	B* b = dynamic_cast<B*> (s); // ��������� ����������
	s->F();
}
// ������� ��� �������������� � 
// ������������ ����������
void f2(B* s) {
	OUT("f2");
	s->A::F();
	s->B::F();
	// s->F(); 
	// ��� ������������ � �������������� 
	// ���������� ���� ����������� �������
}
// ������� ��� �������������� ����������
void f3(A* s) {
	OUT("f3");
	s->F();
}
// ������� ��� �������������� � ������������ ����������
void f4(C* s) {
	OUT("f4");
	
	s->A::F();
	// s->F(); 
	// ��� ������������ � �������������� 
	// ���������� ���� ����������� �������
}
void main() {
	A* a = new A;
	f1(a);
	// ��������� ����������
	f2(dynamic_cast<B*> (a));
	B* b = new B;
	// ���������  ����������
	// ��� ���� �� � my2(b);
	f3(dynamic_cast<A*> (b));
	C* c = new C;
	// ���������� ����������
	f2(dynamic_cast<B*> (c));
	// ���������� ����������
	f4(dynamic_cast<C*> (b));
	system("pause");
}
