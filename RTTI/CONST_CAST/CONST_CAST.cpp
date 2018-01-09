// CONST_CAST.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include<typeinfo>
using namespace std;
void my(char** s) {
	cout << "char* function. Agr is " << typeid(s).name() << ": " << *s << endl;
#pragma warning( disable : 4996)
	char* p1 = new char [4];
	strcpy(p1, "Wow\0");
	*s = p1;
}
void my(int* i) {
	cout << "int* function (begin). Agr is " <<typeid(i).name()<<": "<<*i<<endl;
		*i = 99;
	cout << "int* function (end). Agr is "<<typeid(i).name()<<": "<<*i<<endl;
}
#define OUTT(s, s2) cout << s2 <<" is type - " << typeid(s).name() << ": " << s << endl;
//#define OUT(s) cout << #s <<" is type " << typeid(s).name() << ": " << s << endl;
#define OUT(s) OUTT(s, #s)

int main() {
	int n = 20;
	OUT(n);
	const int& m = n;
	OUT(m);
	// зміна значення посилання
	const_cast<int&> (m) = 60;
	OUTT(n, " n new = ");
	OUTT(m, " m new = ");
	
	//оголошення константного вказівника
	const int nn = 100;
	const int* const mm = &nn;
	OUT(nn);
	OUT(*mm);
	OUT(mm);
	my(const_cast<int*> (mm));
	OUT(nn);
	OUT(*mm);
	OUT(mm);
	my(const_cast<int*> (&nn));
	OUT(nn);
	
	// передавання константних об'єктів  
	// неконстатним функціям
	const char *const p = "My pointer";
	OUT(p);
	my(const_cast<char**> (&p));
	OUT(p);
	

	system("pause");
	return 0;
}

