#include <iostream>
//#include "Vlad.h"
#include "Viktor.h"
#include "windows.h"
using namespace std;

int main () {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ввід кількості рядків
	int n;
	cout << "Введіть кількість рядків:\n-> ";
	cin >> n;

	// ввід даних
	char** strings = new char* [n];
	cin.ignore();
	for (int i = 0; i < n; i++) {
		strings[i] = new char[256];
		cout << i + 1 << ". ";
		cin.getline(strings[i], 255);
	}

	// перевірка рядків на унікальність
	//compare(strings, n);

	// ввід довжини рядків
	int outSize;
	cout << "Введіть довжину рядків:\n-> ";
	cin >> outSize;

	// скорочення рядків
	bool reduction = reduce(strings, n, outSize, 0);

	// вивід даних
	if (reduction) {
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ". " << strings[i] << endl;
		}
	}
	else {
		cout << "Неможливо скоротити рядки, щоб всі були унікальними.\n";
	}

	for (int i = 0; i < n; i++)
		delete[] strings[i];
	delete[] strings;
	return 0;
	return 0;
}

