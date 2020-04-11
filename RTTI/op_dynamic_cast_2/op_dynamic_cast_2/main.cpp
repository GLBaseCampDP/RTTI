#include <iostream>
#include <typeinfo>
using namespace std;
#define  OUT(S) cout << S <<": Cast result is - " \
  << typeid(s).name() << '\n';
#define  VOUT(S) { cout <<"Virtual f call from " \
  << S << '\n'; };

struct A { virtual void F() VOUT("AAAAA");};
struct B : public A { void F() VOUT("BBBBB");};
struct C : public A { void F() VOUT("CCCCC"); };

// функція для підвищувального приведення
// приведення здійснюється в тілі функції
void f1(A* s) {  OUT("f1");
 // понижуюче приведення
 B* b = dynamic_cast<B*> (s); s->F();
}
// понижувальне і  перехресне приведення
void f2(B* s) { OUT("f2");  s->A::F();  s->B::F();
// s->F(); помилка
 }
// підвищувальне приведення
void f3(A* s) { OUT("f3");  s->F();  }
// понижувальне і перехресну приведення
void f4(C* s) {  OUT("f4"); s->A::F();
// s->F(); помилка
}

int main() {
 A* a = new A;	 f1(a);
 // понижуюче приведення
 f2(dynamic_cast<B*> (a));
 B* b = new B;
 // підвищуюче  приведення теж саме що й f3(b);
 f3(dynamic_cast<A*> (b));
 C* c = new C;
 // перехресне приведення
 f2(dynamic_cast<B*> (c));
 // перехресне приведення
 f4(dynamic_cast<C*> (b));
}
