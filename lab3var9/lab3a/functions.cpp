#include "includes.h"

void sumOfNegative(int* mass, int* sum, int* neg, int size) {
	for (int i = 0; i < size; i++) {
		if (*(mass + i) < 0) {
			*sum += *(mass + i);
			(*neg)++;
		}
	}
}

void menu() {
	cout << "����� �������� �� ������ ����� ����� ������������� �����?" << endl << endl;
	cout << "1 - ����� ������������� �����" << endl;
	cout << "2 - ����� ���������� ����� " << endl;
	cout << "3 - ��� ������������� ���������� " << endl;
	cout << "4 - ��������� ������ ���������� " << endl;
	cout << "5 - ����� ��������� �� ��������� " << endl;
	cout << "6 - � ���� ������� � ����������� � ���������� " << endl;
	cout <<">> ";

}