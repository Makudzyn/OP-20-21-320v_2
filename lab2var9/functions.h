#pragma once
#include <iostream>
#include <ctime>
#include "mystruct.h"
using namespace std;

#define DEBUG
#define PRINT_TYPE 1

void byHand(int size, packages offpckgs[]);
void byRandom(int size, packages offpckgs[]);
void sorting(int size, packages offpckgs[]);
void printMenu();
void printTable(int size, packages offpckgs[]);

void printMenu2(int size, packages offpckgs[]) {
#if (PRINT_TYPE == 1)
	byRandom(size, offpckgs);
#else 
	byHand(size, offpckgs);
#endif 
}

void byHand(int size, packages offpckgs[]) {
	for (int i = 0; i < size; i++) {
		setlocale(LC_ALL, "ru");
		printf("Введите наименование: ");            cin >> offpckgs[i].title;
		if (strcmp(offpckgs[i].title, "***") == 0) break;
		printf("Введите производителя: ");           cin >> offpckgs[i].producer;
		printf("Введите кол-во составных частей: "); scanf_s("%d", &(offpckgs)[i].count);
		printf("Введите цену: ");                    scanf_s("%lf", &(offpckgs)[i].price);
	}
#ifdef DEBUG
	cout << "Имя файла >> " << __FILE__ << endl;
	cout << "Дата >> " << __DATE__ << endl;
	cout << "Время >> " << __TIME__ << endl;
	cout << "Функция >> " << __FUNCTION__ << endl;
#endif
}

void byRandom(int size, packages offpckgs[]) {
	setlocale(LC_ALL, "ru");
	srand(time_t(0));
	int* namesArr = new int[size];
	int* producArr = new int[size];
	bool checker;
	int random;
	for (int i = 0; i < size;) {
		random = rand() % 10;
		checker = true;

		for (int j = 0; j < size; j++) {
			if (random == namesArr[j])
				checker = false;
		}
		if (checker) {
			namesArr[i] = random;
			i++;
		}
	}
	for (int i = 0; i < size;) {
		random = rand() % 10;
		checker = true;

		for (int j = 0; j < size; j++) {
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
	for (int i = 0; i < size; i++) {
		int tmp1 = namesArr[i];
		int tmp2 = producArr[i];
		strcpy_s(offpckgs[i].title, namesList[tmp1]);
		strcpy_s(offpckgs[i].producer, producersList[tmp2]);
		offpckgs[i].count = rand() % 15 + 1;
		offpckgs[i].price = rand() % 200 + 100 - 0.1;
	}
	delete[] namesArr;
	delete[] producArr;
#ifdef DEBUG
	cout << "Имя файла >> " << __FILE__ << endl;
	cout << "Дата >> " << __DATE__ << endl;
	cout << "Время >> " << __TIME__ << endl;
	cout << "Функция >> " << __FUNCTION__ << endl;
#endif
}

void sorting(int size, packages offpckgs[]) {
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
#ifdef DEBUG
	cout << "Имя файла >> " << __FILE__ << endl;
	cout << "Дата >> " << __DATE__ << endl;
	cout << "Время >> " << __TIME__ << endl;
	cout << "Функция >> " << __FUNCTION__ << endl;
#endif
}

void printMenu() {
	setlocale(LC_ALL, "rus");
	printf("\nЧто нужно сделать?\n\n");
	printf("1 - Добавить данные в таблицу(выбор будет сделан исходя из начения PRINT_TYPE)\n\n");
	printf("2 - Отсортировать\n\n");
	printf("3 - Напечатать таблицу\n\n");
	printf("0 - Выход из программы\n\n");
#ifdef DEBUG
	cout << "Имя файла >> " << __FILE__ << endl;
	cout << "Дата >> " << __DATE__ << endl;
	cout << "Время >> " << __TIME__ << endl;
	cout << "Функция >> " << __FUNCTION__ << endl;
#endif
}

void printTable(int size, packages offpckgs[]) {
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
#ifdef DEBUG
	cout << "Имя файла" << __FILE__ << endl;
	cout << "Дата" << __DATE__ << endl;
	cout << "Время" << __TIME__ << endl;
	cout << "Функция" << __FUNCTION__ << endl;
#endif
}


