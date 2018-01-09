// DYNAMIC_CAST 2.cpp: определяет точку входа для консольного приложения.
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

// функція для підвищувального приведення
// приведення здійснюється в тілі функції
void f1(A* s) {
	OUT("f1");
	//cout << "my: Cast result is pointer on "
	//	<< typeid(s).name() << endl;
	B* b = dynamic_cast<B*> (s); // понижуюче приведення
	s->F();
}
// функція для понижувального і 
// перехресного приведення
void f2(B* s) {
	OUT("f2");
	s->A::F();
	s->B::F();
	// s->F(); 
	// для перехресного і понижувального 
	// приведення буде згенерована помилка
}
// функція для підвищувального приведення
void f3(A* s) {
	OUT("f3");
	s->F();
}
// функція для понижувального і перехресного приведення
void f4(C* s) {
	OUT("f4");
	
	s->A::F();
	// s->F(); 
	// для перехресного і понижувального 
	// приведення буде згенерована помилка
}
void main() {
	A* a = new A;
	f1(a);
	// понижуюче приведення
	f2(dynamic_cast<B*> (a));
	B* b = new B;
	// підвищуюче  приведення
	// теж саме що й my2(b);
	f3(dynamic_cast<A*> (b));
	C* c = new C;
	// перехресне приведення
	f2(dynamic_cast<B*> (c));
	// перехресне приведення
	f4(dynamic_cast<C*> (b));
	system("pause");
}
