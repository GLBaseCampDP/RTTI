// REINTERPRET_CAST.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
int main()
{
	int i;
	int *p = &i;
	cout << "&i - "  <<	p << endl;
	// ���������� ��������� �� ������ �����
	i = reinterpret_cast<int> (p);
	cout << " i " << i
		<< endl;
	cout << "HEX i 	" << hex << i << endl;
		return 0;
}

