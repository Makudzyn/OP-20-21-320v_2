#include "includes.h"
#include "struct.h"
#include "functions.h"

int main() {
	system("chcp 1251");
	system("cls");

	packages fpacks{};                       
	FILE* file = 0;                            //рабочий файл
	int lines = 0, point = 0, size = 0;

	while(true) {
		printf("\n1 - Ввод с экрана и запись в файл\n");
		printf("\n2 - Ввод случайным образом и запись в файл\n");
		printf("\n3 - Добавить запись в начало файла\n");
		printf("\n4 - Добавить запись в конец файла\n");
		printf("\n5 - Печать одной записи из файла по номеру\n");
		printf("\n6 - Печать всех записей из файла \n");
		printf("\n7 - Выход из программы \n");
		printf(">> "); scanf_s("%d", &point);

		if (point == 1 || point == 2) {
			printf("Сколько строк вы хотите заполнить >> "); scanf_s("%d", &size);
		}

		switch (point) {
			
		case 1:	fillingFileByHand(file, fpacks, size, lines); //Заполнение вводом вручную
			break;

		case 2: fillingFileByRandom(file, fpacks, size, lines); //Заполнение автоматическим вводом 
			break;

		case 3:	addToBegining(file, fpacks, lines); //Добавление строки в начало файла
			break;

		case 4: addToEnd(file, fpacks, lines); //Добавление строки в конец файла
			break;

		case 5: printSelectedString(file, fpacks, lines); //Печать выбранной строки 
			break;

		case 6: printEntireFile(file, fpacks, lines); //Печать всего файла
			break;

		case 7: return 0;

		default: printf("Вы ввели не ту цифру!\n"); break;

		}
	}
}