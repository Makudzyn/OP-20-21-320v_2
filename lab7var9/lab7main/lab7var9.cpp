#include "includes.h"
#include "struct.h"
#include "functions.h"

int main() {
	system("chcp 1251");
	system("cls");

	packages fpacks{};                       
	FILE* file = 0;                            //������� ����
	int lines = 0, point = 0, size = 0;

	while(true) {
		printf("\n1 - ���� � ������ � ������ � ����\n");
		printf("\n2 - ���� ��������� ������� � ������ � ����\n");
		printf("\n3 - �������� ������ � ������ �����\n");
		printf("\n4 - �������� ������ � ����� �����\n");
		printf("\n5 - ������ ����� ������ �� ����� �� ������\n");
		printf("\n6 - ������ ���� ������� �� ����� \n");
		printf("\n7 - ����� �� ��������� \n");
		printf(">> "); scanf_s("%d", &point);

		if (point == 1 || point == 2) {
			printf("������� ����� �� ������ ��������� >> "); scanf_s("%d", &size);
		}

		switch (point) {
			
		case 1:	fillingFileByHand(file, fpacks, size, lines); //���������� ������ �������
			break;

		case 2: fillingFileByRandom(file, fpacks, size, lines); //���������� �������������� ������ 
			break;

		case 3:	addToBegining(file, fpacks, lines); //���������� ������ � ������ �����
			break;

		case 4: addToEnd(file, fpacks, lines); //���������� ������ � ����� �����
			break;

		case 5: printSelectedString(file, fpacks, lines); //������ ��������� ������ 
			break;

		case 6: printEntireFile(file, fpacks, lines); //������ ����� �����
			break;

		case 7: return 0;

		default: printf("�� ����� �� �� �����!\n"); break;

		}
	}
}