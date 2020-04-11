#include <iostream>
#include <typeinfo>
using namespace std;

struct BaseClass {
 virtual void f() {};
};
struct Derivedl : public BaseClass {
 virtual void f() {}; // реаліз. поліморфізм
};
struct  Derived2 : public BaseClass {
 virtual void f() {}; // реаліз. поліморфізм
};
int main() {
 int i;
 BaseClass *p, b; Derivedl o1; Derived2 o2;
 // Вивід на екран інформації про тип
 std::cout << "Типом змінної i є ";
 std::cout << typeid(i).name() << endl;
 // Реалізація поліморфізму
 p = &b;
 std::cout<<" р вказує на об’єкт типу ";
 std::cout << typeid (*p).name() << endl;
 p = &o1;
 std::cout << " р вказує на об’єкт типу ";
 std::cout << typeid(*p).name() << endl;
 p = &o2;
 std::cout << " р вказує на об’єкт типу ";
 std::cout << typeid(*p).name() << endl;
}
