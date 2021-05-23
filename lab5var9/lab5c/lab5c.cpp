#include "includes.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	void (*sortPtr)(int*, int) = NULL;
	int size, point; 

	cout << "������� ������ ������� >>"; cin >> size;
	
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		*(arr + i) = rand() % 100 - 50;
		cout << setw(4) << *(arr + i);
	}

	
	cout << "\n\n�������� ����� ���������� �������: " << endl;
	cout << "1. ���������� ���������" << endl;
	cout << "2. ������ ����������" << endl;
	cout << "3. ������� ����������" << endl;
	cout << ">> "; cin >> point;

	switch (point) {
	case 1:
		cout << "��������� ���������...\n" << endl;
		sortPtr = bubbleSort;
		break;
	case 2:
		cout << "��������� ������...\n" << endl;
		sortPtr = gnomeSort;
		break;
	case 3:
		cout << "\n��������� ������� �����������..." << endl;
		sortPtr = quick;
		break;
	default:
		cout << "Something went wrong..." << endl;
		return 0;
	}

	sortSelect(arr, size, sortPtr);  //  ����� ������� ����������,������� ���������� � ���������

	cout << "��������������� ������: \n";	
	for (int i = 0; i < size; i++) {
		cout << setw(4) << *(arr + i);
	}

	delete[] arr;

	return 0;
}