#include "structs.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "ru");

	int point = 0, count = 0, size = 0, poz;
	Tlist* head = NULL;
	Tlist* next = NULL;
	Tlist* prev = NULL;
	Tlist* tail = NULL;

	while (true) {
		menu();	scanf_s("%d", &point);
		switch (point) {
		case 1:
			printf("Как заполнить?\n");
			printf("1. Автоматически\n");
			printf("2. Вручную\n");
			printf(">> ");	scanf_s("%d", &point);
			if (point == 1) {
				printf("Введите сколько елементов списка создать >> "); scanf_s("%d", &size);
			}

			listCreation(head, tail, count, point, size);
			break;

		case 2:	listPrintFromHead(head);
			break;

		case 3:	listPrintFromTail(tail);
			break;

		case 4:	searchByParamFromHead(head, count);
			break;

		case 5:	searchByParamFromTail(tail, count);
			break;

		case 6:
			printf("На какою позицию вставить елемент >> "); scanf_s("%d", &poz);
			addToList(head, count, poz);
			break;

		case 7:
			printf("Введите позицию удаляемого элемента >> "); scanf_s("%d", &poz);
			deleteFromList(head, count, poz);
			break;

		case 8:	listSorting(head, count);
			break;

		case 9:	createFile(head, count);
			break;

		case 10:
			oldListKill(head);
			createListFromFile(head, tail);
			break;

		case 11: oldListKill(head); return 0;

		default: printf("Wrong number!\n");
			break;
		}
	}
	return 0;
}
