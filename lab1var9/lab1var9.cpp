#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>
using namespace std;

struct packages{
	char title[40];
	char producer[40];
	int count; 
	double price;
}offpckgs[10], thx;

void byHand(int size) {
	for (int i = 0; i < size; i++) {
		setlocale(LC_ALL, "ru");
		printf("Введите наименование: ");            /*scanf_s("%s", &(offpckgs)[i].title);*/ cin >> offpckgs[i].title;
		if (strcmp(offpckgs[i].title, "***") == 0) break;
		printf("Введите производителя: ");           /*scanf_s("%s", &(offpckgs)[i].producer);*/ cin >> offpckgs[i].producer;
		printf("Введите кол-во составных частей: "); scanf_s("%d", &(offpckgs)[i].count);
		printf("Введите цену: ");                    scanf_s("%lf", &(offpckgs)[i].price);
	}
	
}


void byRandom(int size){
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int* namesArr = new int[size];
	int* producArr = new int[size];
	bool checker;
	int random;
	for (int i = 0; i < size;){
		random = rand() % 10;
		checker = true; 

		for (int j = 0; j < size; j++) {
			if (random == namesArr[j])
				checker = false;
		}
		if (checker){
			namesArr[i] = random;
			i++;
		}
	}
	for (int i = 0; i < size;)	{
		random = rand() % 10;
		checker = true;

		for (int j = 0; j < size; j++)	{
			if (random == producArr[j])
				checker = false;
		}
		if (checker) {
			producArr[i] = random;
			i++;
		}
	}
	char namesList[][15] = { "Office","SmartSute","pdfReader","Paint","DriverBooster","MemReduct","ImageViewer","Telegram","Torrent","Blender" };
	char producersList[][15] = { "Microsoft","Supercell","IObit","Sun","Oracle","SAP SG","Symantec","Nintendo","Adobe","E.A" };
	for (int i = 0; i < size; i++)	{
		int tmp1 = namesArr[i];
		int tmp2 = producArr[i];
		strcpy_s(offpckgs[i].title, namesList[tmp1]);
		strcpy_s(offpckgs[i].producer, producersList[tmp2]);
		offpckgs[i].count = rand() % 15 + 1;
		offpckgs[i].price = rand() % 200 + 100 - 0.1;
	}
	delete[] namesArr; 
	delete[] producArr;
}

void sorting(int size) {
	for (int i = 0; i < size; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++)
			if (strcmp(offpckgs[min].title, offpckgs[j].title) > 0)
				min = j;
		if (min > i) {
			thx = offpckgs[i];
			offpckgs[i] = offpckgs[min];
			offpckgs[min] = thx;
		}
	}
}

void printMenu() {
	setlocale(LC_ALL, "rus");
	printf("Что нужно сделать?\n");
	printf("1 - Добавить данные в таблицу в ручную\n");
	printf("2 - Добавить случайные данные в таблицу\n");
	printf("3 - Отсортировать\n");
	printf("4 - Напечатать таблицу\n");
	printf("0 - Выход из программы\n");
	printf(">");
}

void printTable(int size) {
	setlocale(LC_ALL, "rus");
	printf("|-------------------------------------------------------------|\n");
	printf("|                        Офисные пакеты                       |\n");
	printf("|-------------------------------------------------------------|\n");
	printf("| Наименование | Производитель | Кол-во сост.частей | Цена($) |\n");
	printf("|--------------|---------------|--------------------|---------|\n");
	if (size == 0)
	printf("|                    Пока тут ничего нет...                   |\n");

	for (int i = 0; i < size; i++) {
    printf("|%-13s | %-13s | %-18d | %-0.2lf  |\n", offpckgs[i].title, offpckgs[i].producer, offpckgs[i].count, offpckgs[i].price);
	}
	printf("|-------------------------------------------------------------|\n");
}

int main(void) {
	setlocale(LC_ALL, "ru");
	int size, point;
	cout << "Введите количество рядов таблицы: "; cin >> size;
	do {
		printMenu();
		scanf_s("%d", &point);
		while (point < 0 || point > 5) {
			printf("Что-то пошло не так...\nПопробуйте снова: "); scanf_s("%d", &point); 
		}
		switch (point) {
		case 1:
			byHand(size);
			break;
		case 2:
			byRandom(size);
			break;
		case 3:
			sorting(size);
			break;
		case 4:
			printTable(size);
			break;
		}
	} while (point != 0);
	return 0;
}