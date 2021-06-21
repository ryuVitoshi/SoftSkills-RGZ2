#include <iostream>
#include "Vlad.h"
#include "Viktor.h"
#include "windows.h"
using namespace std;

// додаткова функція для роботи вдвох
void func(char** str, int n) {
	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				matrix[i][i] = 0;
				continue;
			}
			for (int k = 0; str[i][k] != '\0' || str[j][k] != '\0'; k++) {
				if (str[i][k] != str[j][k]) {
					matrix[i][j] = k;
					matrix[j][i] = k;
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	char** strings = NULL;

	try {
		// ввід кількості рядків
		cout << "Введіть кількість рядків:\n-> ";
		cin >> n;
		if (n < 1) throw 1;

		// ввід даних
		strings = new char* [n];
		cin.ignore();
		for (int i = 0; i < n; i++) {
			strings[i] = new char[256];
			cout << i + 1 << ". ";
			cin.getline(strings[i], 255);
		}

		// перевірка рядків на унікальність
		compare(strings, n);

		// ввід довжини рядків
		int outSize;
		cout << "Введіть довжину рядків:\n-> ";
		cin >> outSize;
		if (outSize < 2) throw 2;

		// скорочення рядків
		bool reduction = reduce(strings, n, outSize, 0);

		// вивід даних
		if (reduction) {
			for (int i = 0; i < n; i++) {
				cout << i + 1 << ". " << strings[i] << endl;
			}
		}
		else {
			throw 3;
		}

	}
	catch (int Exception) {
		switch (Exception) {
		case 1:
			cout << "Кількість рядків повинна бути більше 0.\n";
			break;
		case 2:
			cout << "Довжина рядків повинна бути більше 1.\n";
			break;
		case 3:
			cout << "Неможливо скоротити рядки, щоб всі були унікальними.\n";
		}
	}

	for (int i = 0; i < n; i++)
		delete[] strings[i];
	delete[] strings;
	system("pause");
	return 0;
}