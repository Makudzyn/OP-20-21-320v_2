#pragma once
#define foo1
#ifdef foo1
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
using namespace std;

void arrFilling(int mainSize, int mainArr[], int minusArr[], int plusArr[], int nullArr[],
	int* size1, int* size2, int* size3) {

	int z = 0, x = 0, c = 0;
	cout << "Основной массив : ";
	for (int i = 0; i < mainSize; i++) {
		mainArr[i] = rand() % 5 - 2;
		cout << setw(4) << mainArr[i];
		if (mainArr[i] < 0) {
			(*size1)++;
			minusArr[z] = mainArr[i];
			z++;
		}
		else if (mainArr[i] > 0) {
			(*size2)++;
			plusArr[x] = mainArr[i];
			x++;
		}
		else {
			(*size3)++;
			nullArr[c] = mainArr[i];
			c++;
		}
	}
}

void mainFilling(int mainArr[], int nullArr[], int plusArr[], int minusArr[],
	int size1, int size2, int size3) {
	int k = 0;
	for (; k < size3; k++)
		mainArr[k] = nullArr[k];
	int k1 = k;
	for (int h = 0; k < k1 + size1; k++, h++)
		mainArr[k] = minusArr[h];
	k1 = k;
	for (int h = 0; k < k1 + size2; k++, h++)
		mainArr[k] = plusArr[h];
}
#endif // foo1

