#include <iostream>
using namespace std;
int main() {
  int i;
  int *p = &i;
  std::cout << "&i - "  << p << '\n';
// Приведення вказівника до цілого числа
  i = reinterpret_cast<long> (p);
  std::cout << " i " << i << '\n';
  std::cout << "HEX i " << hex << i << '\n';
}
