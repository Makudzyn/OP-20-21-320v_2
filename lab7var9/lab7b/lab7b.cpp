#include "includes.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	int const SIZE = 10;
	int* mas1 = new int[SIZE];
	int* mas2 = new int[SIZE];
	FILE* file = {};

	cout << "�������� ������" << endl;
	massFillingAndPrintin(mas1, SIZE);

	fileFilling(file, mas1, SIZE);
	cout << "\n����� �� ������� ���� ��������� � ����." << endl;

	fileWorking(file, mas2, SIZE);
	cout << "\n����� ���� ������� �� ����� � ������\n";

	cout << "\n������ ������" << endl;
	for (int i = 0; i < SIZE; i++)	{
		cout << setw(4) << *(mas2 + i);
	}
	cout << "\n����� ������ = " << sumOfNums(mas2, SIZE);

	delete[] mas1;
	delete[] mas2;
	return 0;
}
