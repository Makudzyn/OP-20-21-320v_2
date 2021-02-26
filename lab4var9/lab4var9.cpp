/*В целочисленном массиве определить количество элементов, которые больше предыдущего элемента,
но меньше последующего.Переписать в новый массив все четные элементы. */
//Сделать файл функции.х с шаблонами и файл с их реализацией.cpp
#include "functions.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	int size, counter = 0, pairElems = 0;
	cout << "Введите размер массива >> "; cin >> size;

	//int* mass1 = (int*)malloc(size * sizeof(int));
	//int* mass2 = (int*)malloc(size * sizeof(int));
	int* mass1 = new int[size * sizeof(int)];
	int* mass2 = new int[size * sizeof(int)];

	randArr(mass1, size);//Заполнение случ. числами

	ArrSort(size, mass1, mass2, &pairElems, &counter);//Сортировка

	printMass1(mass1, size);// Вывод первого массива

	cout << "\n\nКол-во чисел > предыдущего и < последующего : " << counter << endl;

	printElems(mass2, pairElems);

	cout << endl;
	delete[] mass1;
	delete[] mass2;
	/*free(mass1);
	free(mass2);*/
}