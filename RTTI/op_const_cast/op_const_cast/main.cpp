#include <iostream>
#include<typeinfo>
#include <string.h>
void my(char** s) {
  std::cout << "char* function. Agr is " <<
    typeid(s).name() << ": " << *s << "\n";
  char* p1 = new char [4]; strcpy(p1, "Wow\0");
  *s = p1;
}
void my(int* i) {
  std::cout << "int* function (begin). Agr is "
  <<typeid(i).name()<<": "<<*i<<"\n";
  *i = 99;
   std::cout << "int* function (end). Agr is "<<typeid(i).name()<<": "<<*i<<"\n";
}
#define OUTT(s, s2) std::cout << s2 <<\
 " is type - "<<typeid(s).name()<<": "<<s<<"\n";
#define OUT(s) OUTT(s, #s)

int main() {
int n = 20;	OUT(n);  const int& m = n;  OUT(m);
// зміна значення посилання
const_cast<int&> (m) = 60;
OUTT(n, " n new = ");	OUTT(m, " m new = ");
//оголошення константного вказівника
const int nn = 100;
const int* const mm = &nn;
OUT(nn);	OUT(*mm);	OUT(mm);
my(const_cast<int*> (mm));
OUT(nn);	OUT(*mm);	OUT(mm);
my(const_cast<int*> (&nn));
OUT(nn);
// передавання константних об'єктів
// неконстантним функціям
const char *const p = "My pointer";
OUT(p); my(const_cast<char**> (&p)); OUT(p);
}
