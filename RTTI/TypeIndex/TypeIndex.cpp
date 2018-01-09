// TypeIndex.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <typeindex>
#include <vector>
#include <string>
using namespace std;

class d {};

int main() {
	cout << type_index(typeid(double)).name() << endl <<
		type_index(typeid(d)).name() << endl <<
		type_index(typeid(int)).name() << endl;

	//typedef pair<type_index, string> mnames;
	vector< pair<type_index, string> > names;

	auto p = make_pair(type_index(typeid(double)), "double");
	names.push_back(p);
	p = make_pair(type_index(typeid(d)), "class d");
	names.push_back(p);
	p = make_pair(type_index(typeid(int)), "int");
	names.push_back(p);

	for (unsigned i = 0; i< names.size();
		std::cout << names[i].second << endl, i++);
	system("pause");
	return 0;
}


