#include <iostream>
const int sz = 3;
struct X { int a[sz]; };
void print(X* x) {
 for (int i = 0; i < sz; i++)
    std::cout << x->a[i]<< "*\n --------------------\n";
}

int main() {
 X x;
 print(&x);

 int* xp = reinterpret_cast<int*>(&x);

 for (int* i = xp; i < xp + sz; *i = 1, i++);
 print(&x);
}
