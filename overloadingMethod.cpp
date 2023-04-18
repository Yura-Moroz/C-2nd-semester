// overloadingMethod.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void increment(int& var) {
	// Збільшує змінну на 1
	var++;
}

void increment(int& var, int expr) {
	// Збільшує змінну на значення виразу
	var += expr;
}

int main(void) {
	int var = 0;
	for (int i = 0; i < 10; i++)
		if (i % 2)
			increment(var);
		else
			increment(var, i);
	cout << var << endl;
	return 0;
}