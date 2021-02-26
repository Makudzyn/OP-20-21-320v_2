#pragma once
#define foo
#ifdef foo
#include <iostream>
#include <ctime>
#include <iomanip>
#include "functions.h"
using namespace std;
//���-�� ����� > ����������� � < ������������ � ������ �� �� ������ ������
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
	cout << "\n������ ������ :";
	for (int i = 0; i < size; i++)
		cout << setw(4) << mass1[i];
}
void printElems(int mass2[], int pairElems) {
	cout << "\n������ ��������, ������� > ����������� � < ������������ : ";
	if (pairElems != 0) {
		for (int i = 0; i < pairElems; i++)
			cout << setw(4) << mass2[i];
	}
	else {
		cout << "��� �� ������ ��������, ������� �� ������������ �������\n";
	}
}
#endif // foo

