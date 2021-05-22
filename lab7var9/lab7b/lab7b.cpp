#include "includes.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	int const SIZE = 10;
	int* mas1 = new int[SIZE];
	int* mas2 = new int[SIZE];
	FILE* file = {};

	cout << "Основной массив" << endl;
	massFillingAndPrintin(mas1, SIZE);

	fileFilling(file, mas1, SIZE);
	cout << "\nЧисла из массива были записанны в файл." << endl;

	fileWorking(file, mas2, SIZE);
	cout << "\nЧисла были считаны из файла в массив\n";

	cout << "\nВторой массив" << endl;
	for (int i = 0; i < SIZE; i++)	{
		cout << setw(4) << *(mas2 + i);
	}
	cout << "\nСумма четных = " << sumOfNums(mas2, SIZE);

	delete[] mas1;
	delete[] mas2;
	return 0;
}
