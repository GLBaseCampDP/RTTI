// STATIC_CAST.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <limits>

void func(int) {}
int main()
{
	int i = std::numeric_limits<int>::max(); // Максимальне додатнє значение
	long l;
	float f;

	// (1) Типові автоматичні приведення:
	l = i; f = i;
	// Вони також можуть бути виконані
	l = static_cast<long>(i);
	f = static_cast<float>(i);

	// (2) Перетворення із втратою інформації
	i = l; // Можлива втрата даних
	i = f; // Можлива втрата даних
		   // Небезпечне перетворення
	i = static_cast<int>(l);
	i = static_cast<int>(f);
	char c = static_cast<char>(i);

	// (3) Примусове перетворення  void*
	void* vp = &i;
	// Небезпечний спосіб
	float* fp = (float*)vp;
	// Новий спосіб (також небезпечний)
	fp = static_cast<float*>(vp);

	// (4) Неявне приведення типу (зазвичай здійснює компілятор)
	double d = 0.0;
	int x = d; // Автоматичне приведення типу
	x = static_cast<int>(d); // Явне приведенння типу
	func(d); // Автоматичне приведення типу
	func(static_cast<int>(d)); // Явне приведенння типу
}


