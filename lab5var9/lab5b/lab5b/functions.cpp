#include <iostream>
using namespace std;

int sumOfPositive(int const size, int* mass, int counter = 0) {
	for (int i = 0; i < size; i++)
		if (*(mass + i) > 0)
			counter += *(mass + i);
		
	return counter;
}

int compositionOfNegative(int const size, int* mass, int counter = 1) {
	for (int i = 0; i < size; i++)
		if (*(mass + i) < 0)
			counter *= *(mass + i);

	return counter;
}

void menu() {
	cout << "��� �������?\n\n";
	cout << "1 - ��������� ����� �������������\n";
	cout << "2 - ��������� ������������ �������������\n";
	cout << "3 - � ��, � ��\n";
}

int fooSlct(int const size, int* mass) {
	int point; cin >> point;
	if (point == 1) {
		cout << "��������� ���������� : ";
		return sumOfPositive(size, mass);
	}
	else if (point == 2) {
		cout << "��������� ���������� : ";
		return compositionOfNegative(size, mass);
	}
	else if (point == 3) {
		cout << "��������� ���������� : "<< sumOfPositive(size, mass) <<" � "<< compositionOfNegative(size, mass) << endl;
		return 0;
	}
	else
		cout << "Error";
}