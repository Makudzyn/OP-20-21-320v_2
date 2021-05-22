#include "includes.h"
#include "functions.h"


int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	FILE* file = {};
	int const SIZE = 20;
	int sum = 0, poz, min;

	cout << "��������� ���� 20 ���������� �������" << endl;
	fileFilling(file, SIZE);
	
	cout << "\n\n����� 2, 5 � 9 ����� � ����� = "  << sumOf2n5n9(file, sum) << endl;

	findMin(file, SIZE, poz, min);

	cout << "\n���������� ����� = " << min << endl;
	cout << "��������� �� " << poz << " �������\n" << endl;

	cout << "�������� ����������� �� 999" << endl;
	minChangeTo999(file, SIZE, poz);
	cout << endl;
	return 0;
}