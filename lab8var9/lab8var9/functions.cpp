﻿#include "structs.h"
#include "functions.h"

void menu() {
	printf("Что делать?\n");
	printf("1. Создать список \n");
	printf("2. Напечатать список \n");
	printf("3. Поиск по критерию \n");
	printf("4. Добавление элемента \n");
	printf("5. Удаление элемента \n");
	printf("6. Сортировка \n");
	printf("7. Запись списка в файл \n");
	printf("8. Создание нового списка из файла \n");
	printf("9. Выход из программы \n");
	printf(">> ");
}

void listCreation(Tlist*& head, int& count, int point, int size) {
	if (point == 1) { //Автоматически
		srand(time(0));

		int random = 0;
		bool checker;
		int* namesArr = new int[size];
		int* producArr = new int[size];

		for (int i = 0; i < size;) { //В этих циклах побдираются числа от 1 до 10 которые не будут повторяться
			random = rand() % 10;
			checker = true;

			for (int j = 0; j < size; j++) {
				if (random == *(namesArr + j))
					checker = false;
			}
			if (checker) {
				*(namesArr + i) = random;
				i++;
			}
		}
		for (int i = 0; i < size;) {
			random = rand() % 10;
			checker = true;

			for (int j = 0; j < size; j++) {
				if (random == *(producArr + j))
					checker = false;
			}
			if (checker) {
				*(producArr + i) = random;
				i++;
			}
		}

		char namesList[][15] = { "Office","SmartSute","pdfReader","Paint","DriverBooster","MemReduct","ImageViewer","Telegram","Torrent","Blender" };
		char producersList[][15] = { "Microsoft","Supercell","IObit","Sun","Oracle","SAP_SG","Symantec","Nintendo","Adobe","E.A" };


		Tlist* list = new Tlist;
		Tlist* tmpPoz, * tmp;
		tmpPoz = tmp = list;

		for (int i = 0; i < size; i++) { //Заполнение
			int tmp1 = *(namesArr + i);
			int tmp2 = *(producArr + i);
			strcpy_s(tmp->data.title, *(namesList + tmp1));
			strcpy_s(tmp->data.producer, *(producersList + tmp1));
			tmp->data.count = rand() % 20 + 1;
			tmp->data.price = rand() % 100 + 100 - 0.5;
			tmpPoz->next = tmp;
			tmpPoz = tmp;
			tmp = new Tlist;
		}
		tmpPoz->next = NULL;
		count = size;
		head = list;
		delete[] namesArr;
		delete[] producArr;
	}
	else if(point == 2) { //Вручную
		Tlist* tmp = new Tlist;
		printf("Введите >> \n");
		printf("Наименование:  "); scanf_s("%s", tmp->data.title, 15);      setbuf(stdin, NULL);
		printf("Производителя: "); scanf_s("%s", tmp->data.producer, 10);	setbuf(stdin, NULL);
		printf("Количество ч.: "); scanf_s("%d", &tmp->data.count);
		printf("Цену:          "); scanf_s("%lf", &tmp->data.price);
		head = tmp;
		tmp->next = NULL;
		count++;
	}
}

void listPrint(Tlist* head, int count) {
	if (head != NULL) {
		Tlist* tmp;
		tmp = head;
		for (int i = 0; i != count; i++) {
			printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
			tmp = tmp->next;
		}
		printf("\n");
	}
	else printf("\nСперва создайте список.\n"); 
}

int searchByParam(Tlist* head, int count) {
	int point;
	Tlist* tmp;
	Tlist tmpAsk;
	
	while (true) {
		bool rpt = true;
		tmp = head;
		printf("\nИскать по...\n");
		printf("1. Наименованию \n");
		printf("2. Производителю \n");
		printf("3. Кол-ву частей \n");
		printf("4. Цене \n");
		printf("5. Выход\n");
		printf(">> "); scanf_s("%d", &point);

		switch (point) {
		case 1:
			printf("Наименование > "); scanf_s("%s", tmpAsk.data.title, 10); setbuf(stdin, NULL);

			while (tmp != 0) {
				if (strcmp(tmp->data.title, tmpAsk.data.title) == 0) { //Сравниваем с каждым названием
					rpt = false; //Меняем на фолс если есть одинаковый елемент
					printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
				}
				tmp = tmp->next;
			}
			if (rpt) printf("Такого наименования в списке нет.\n\n"); //Если совпадений нет
			break;

		case 2:
			printf("Производитель > "); scanf_s("%s", tmpAsk.data.producer, 10); setbuf(stdin, NULL);

			while (tmp != NULL) {
				if (strcmp(tmp->data.producer, tmpAsk.data.producer) == 0) { //Сравниваем с каждым производителем
					rpt = false; //Меняем на фолс если есть одинаковый елемент
					printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
				}
				tmp = tmp->next;
			}
			if (rpt) printf("Такого производителя в списке нет.\n\n"); //Если совпадений нет
			break;

		case 3:
			printf("Кол-во >");	scanf_s("%d", &tmpAsk.data.count); setbuf(stdin, NULL);

			while (tmp != NULL) {
				if (tmp->data.count == tmpAsk.data.count) {
					rpt = false;
					printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
				}
				tmp = tmp->next;
			}
			if (rpt) printf("Такого количества в списке нет.\n\n");
			break;

		case 4:
			printf("Цена > "); scanf_s("%lf", &tmpAsk.data.price); setbuf(stdin, NULL);

			while (tmp != NULL) {
				if (tmp->data.price == tmpAsk.data.price) {
					rpt = false;
					printf("\n%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
				}
				tmp = tmp->next;
			}
			if (rpt) printf("Такой цены в списке нет.\n\n");
			break;

		case 5: return 0;

		default: printf("Wrong number!\n");
			break;
		}
	}
}

void addToList(Tlist*& head, int& count, int poz) {
	Tlist* tmp = new Tlist;

	if (poz == 1) {
		tmp->next = head;
		head = tmp;
	}
	else {
		Tlist* tmpPoz = head;
		for (int i = 0; i < poz - 2; i++)
			tmpPoz = tmpPoz->next;

		tmp->next = tmpPoz->next;
		tmpPoz->next = tmp;

	}

	printf("\nВведите >> \n");
	printf("Наименование:  "); scanf_s("%s", tmp->data.title, 20);      setbuf(stdin, NULL);
	printf("Производителя: "); scanf_s("%s", tmp->data.producer, 20);	setbuf(stdin, NULL);
	printf("Количество ч.: "); scanf_s("%d", &tmp->data.count);
	printf("Цену:          "); scanf_s("%lf", &tmp->data.price);
	count++;
}

void deleteFromList(Tlist*& head, int& count, int poz) {
	if (head != NULL) {
		Tlist* tmpPoz = head;

		if (poz == 1) { //Если елемент первый
			head = head->next; //Перемещаем указатель начала на след. елемент
			delete tmpPoz;
		}
		else {
			for (int i = 0; i < poz - 2; i++) //Перемещаемся к елементу указывающему на нужный(середина)
				tmpPoz = tmpPoz->next;

			Tlist* tmp = tmpPoz->next;

			if (tmp->next == NULL) tmpPoz->next = NULL; //Если елемент последний
			else tmpPoz->next = tmp->next;              //Если не последний
			delete tmp;
		}
		count--;
	}else printf("\nСперва создайте список.\n");
}

void listSorting(Tlist* head, int count) {
	if (head != NULL) {
		Tlist* temp = head;
		Tlist* hPtr, * trash, *tmp;
		tmp = new Tlist;

		for (int i = 0; i < count; i++) {
			hPtr = head;                 //Присваиваем начало списка
			while (hPtr->next != NULL) { //Пока список не кончиться
				temp = hPtr->next;        //Присваиваем следущий елемент списка перем. 
				if (strcmp(hPtr->data.title, temp->data.title) > 0) { //Сравниваем строки с помощью стрсмп
					trash = temp->next;   //Записываем указатель на некст елемент
					*tmp = *hPtr;         //Сохраняем указатель на текущий елемент
					*hPtr = *temp;        //Присваеваем следующий(2) елемент на начало списка
					delete temp;
					hPtr->next = new Tlist; //К новому первому елементу привязываем список
					*hPtr->next = *tmp;     //Теперь текущий первый указывает на предыдущий
					hPtr->next->next = trash;
				}
				hPtr = hPtr->next;
			}
		}
		delete tmp;
	}
	else printf("\nСперва создайте список.\n");
}

void createFile(Tlist* head, int count) {
	if (head != NULL) {
		Tlist* tmp = head;
		FILE* file = 0;

		if ((file = fopen("fileForList.txt", "w")) == NULL) { //Открываем файл и проверяем существует ли он
			printf("Файл для записи не найден");
			exit(1);
		}

		for (int i = 0; i != count; i++) {
			fprintf_s(file, "%-14s %-10s %-3d %.2lf\n", tmp->data.title, tmp->data.producer, tmp->data.count, tmp->data.price);
			tmp = tmp->next;
		}
		fclose(file);
	}
	else printf("\nСперва создайте список.\n");
}

void oldListKill(Tlist*& head) {
	Tlist* tmp = head;
	while (tmp) {
		head = head->next;
		delete tmp;
		tmp = head;
	}
}

void createListFromFile(Tlist*& head) {
	FILE* file = NULL;
	if ((file = fopen("fileForList.txt", "r")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для чтения не найден");
		exit(1);
	}

	int count = 0;
	char text;
	while (true) {
		text = fgetc(file);
		if (text == '\n')count++;
		else if (text == EOF) break;
	}

	head = new Tlist;
	Tlist* tmpPoz, *tmp;
	tmpPoz = tmp = head;

	fseek(file, 0, SEEK_SET); //СУПЕР ВАЖНАЯ СТРОКА, БЕЗ НЕЕ ФУНКЦИЯ НЕ РАБОТАЕТ =)
	for (int i = 0; i != count; i++) {
		fscanf_s(file, "%s", tmp->data.title, 20);
		fscanf_s(file, "%s", tmp->data.producer, 20);
		fscanf_s(file, "%d", &tmp->data.count);
		fscanf_s(file, "%lf", &tmp->data.price);
		tmpPoz->next = tmp;
		tmpPoz = tmp;
		tmp = new Tlist;
	}
	tmpPoz->next = NULL;
	fclose(file);
}