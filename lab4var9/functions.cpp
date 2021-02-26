#pragma once
#define foo
#ifdef foo
#include <iostream>
#include <ctime>
#include <iomanip>
#include "functions.h"
using namespace std;
//Кол-во чисел > предыдущего и < последующего и запись их во второй массив
void ArrSort(int size, int mass1[], int mass2[], int* pairElems, int* counter) {
	for (int k = 1; k < size - 1; k++) {
		if ((mass1[k] > mass1[k - 1]) && (mass1[k] < mass1[k + 1])) {
			(*counter)++;
			if (mass1[k] % 2 == 0) {
				mass2[*pairElems] = mass1[k];
				(*pairElems)++;
			}
		}
	}

}
void randArr(int mass1[], int size) {
	for (int i = 0; i < size; i++)
		mass1[i] = rand() % 100 - 25;
}
void printMass1(int mass1[], int size) {
	cout << "\nПервый массив :";
	for (int i = 0; i < size; i++)
		cout << setw(4) << mass1[i];
}
void printElems(int mass2[], int pairElems) {
	cout << "\nЧетные елементы, которые > предыдущего и < последующего : ";
	if (pairElems != 0) {
		for (int i = 0; i < pairElems; i++)
			cout << setw(4) << mass2[i];
	}
	else {
		cout << "Нет ни одного елемента, который бы удовлетворял условию\n";
	}
}
#endif // foo

