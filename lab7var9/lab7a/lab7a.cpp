#include "includes.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "ru");
	FILE* file1 = {}, * file2 = {};
	int const SIZE = 10;
	int* mas1 = new int[SIZE];
	int* mas2 = new int[SIZE];
	int x;

	cout << "Основной массив" << endl;
	arrWorking(mas1, SIZE);

	
	fromArrToFile1(file1, mas1, SIZE);
	cout << "\n\nЧисла из основного массива записанны в файл№1" << endl;

	fromFileToArrAndFile2(file1, file2, mas1, mas2, SIZE);

	cout << "\nВторой массив" << endl;
	for (int i = 0; i < SIZE; i++){
		cout << setw(4) << *(mas2 + i);
	}

	cout << "\n\nПереписываем в переменнную и выводим" << endl;
	file2Print(file2, x, SIZE);

	delete[] mas1;
	delete[] mas2;
	return 0;
}