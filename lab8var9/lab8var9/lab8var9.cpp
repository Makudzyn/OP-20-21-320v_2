#include "structs.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "ru");

	int point = 0, count = 0, size = 0, poz;
	Tlist* head = NULL;
	Tlist* next = NULL;

	while (true) {
		menu();	scanf_s("%d", &point);
		switch (point) {
		case 1:
			printf("��� ���������?\n");
			printf("1. �������������\n"); 
			printf("2. �������\n");
			printf(">> ");	scanf_s("%d", &point);
			if (point == 1)	{
				printf("������� ������� ��������� ������ ������� >> "); scanf_s("%d", &size);
			}

			listCreation(head, count, point, size);
			break;

		case 2:	listPrint(head, count);
			break;

		case 3:	searchByParam(head, count);
			break;

		case 4:
			printf("�� ����� ������� �������� ������� >> "); scanf_s("%d", &poz);
			addToList(head, count, poz);
			break;

		case 5: 
			printf("������� ������� ���������� �������� >> "); scanf_s("%d", &poz);
			deleteFromList(head, count, poz);
			break;

		case 6:	listSorting(head, count);
			break;

		case 7:	createFile(head, count);
			break;

		case 8: 
			oldListKill(head);
			createListFromFile(head);
			break;

		case 9: oldListKill(head); return 0;

		default: printf("Wrong number!\n");
			break;
		}
	}
	return 0;
}
