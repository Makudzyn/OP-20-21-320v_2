#include "includes.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	void (*sortPtr)(int*, int) = NULL;
	int size, point; 

	cout << "Введите размер массива >>"; cin >> size;
	
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		*(arr + i) = rand() % 100 - 50;
		cout << setw(4) << *(arr + i);
	}

	
	cout << "\n\nВыберете метод сортировки массива: " << endl;
	cout << "1. Сортировка пузырьком" << endl;
	cout << "2. Гномья сортировка" << endl;
	cout << "3. Быстрая сортировка" << endl;
	cout << ">> "; cin >> point;

	switch (point) {
	case 1:
		cout << "Сортируем пузырьком...\n" << endl;
		sortPtr = bubbleSort;
		break;
	case 2:
		cout << "Сортируем гномом...\n" << endl;
		sortPtr = gnomeSort;
		break;
	case 3:
		cout << "\nСортируем быстрой сортировкой..." << endl;
		sortPtr = quick;
		break;
	default:
		cout << "Something went wrong..." << endl;
		return 0;
	}

	sortSelect(arr, size, sortPtr);  //  Вызов функции сортировки,которая находиться в указатель

	cout << "Отсортированный массив: \n";	
	for (int i = 0; i < size; i++) {
		cout << setw(4) << *(arr + i);
	}

	delete[] arr;

	return 0;
}