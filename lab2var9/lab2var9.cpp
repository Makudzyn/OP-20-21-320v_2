#include "functions.h"


int main(void) {
	setlocale(LC_ALL, "ru");
	int size, point;
	cout << "������� ���������� ����� �������: "; cin >> size;
	cout << endl;
	do {
		printMenu();
		scanf_s("%d", &point);
		cout << endl;
		while (point < 0 || point > 4) {
			printf("���-�� ����� �� ���...\n���������� �����: "); scanf_s("%d", &point);
		}
		switch (point) {
		case 1:
			printMenu2(size, offpckgs);
			break;
		case 2:
			sorting(size, offpckgs);
			break;
		case 3:
			printTable(size, offpckgs);
			break;
		}
	} while (point != 0);
	return 0;
}