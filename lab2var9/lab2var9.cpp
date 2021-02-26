#include "functions.h"


int main(void) {
	setlocale(LC_ALL, "ru");
	int size, point;
	cout << "Введите количество рядов таблицы: "; cin >> size;
	cout << endl;
	do {
		printMenu();
		scanf_s("%d", &point);
		cout << endl;
		while (point < 0 || point > 4) {
			printf("Что-то пошло не так...\nПопробуйте снова: "); scanf_s("%d", &point);
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