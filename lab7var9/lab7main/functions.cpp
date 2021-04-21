#include "includes.h"
#include "struct.h"


void fillingFileByHand(FILE* file, packages fpacks, int size, int& lines) {

	if ((file = fopen("file.txt", "w")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для записи не найден");
		exit(1);
	}

	for (int i = 0; i < size; i++) {   //Запись в файл
		printf("Введите: наименование, производителя, кол-во и цену >> \n");
		scanf("%s", fpacks.title);      setbuf(stdin, NULL);	//отключает буфер, то есть делает небуферизованный ввод
		if (strcmp(fpacks.title, "***") == 0) break;             //Выход при введении ***
		scanf("%s", fpacks.producer);	setbuf(stdin, NULL);
		scanf("%d", &fpacks.count);
		scanf("%lf", &fpacks.price);
		fprintf(file, "%-14s %-10s %-3d %.2lf\n", fpacks.title, fpacks.producer, fpacks.count, fpacks.price);
	}
	fclose(file);
	lines=size;
}

void fillingFileByRandom(FILE* file, packages fpacks, int size, int& lines){
	srand(time(0));

	int random;
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
	
	if ((file = fopen("file.txt", "w")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для записи не найден");
		exit(1);
	}

	for (int i = 0; i < size; i++) { //Заполнение
		int tmp1 = *(namesArr + i);
		int tmp2 = *(producArr + i);
		strcpy_s(fpacks.title, *(namesList + tmp1));
		strcpy_s(fpacks.producer, *(producersList + tmp1));
		fpacks.count = rand() % 20 + 1;
		fpacks.price = rand() % 100 + 100 - 0.5;
		fprintf(file, "%-14s %-10s %-3d %.2lf\n", fpacks.title, fpacks.producer, fpacks.count, fpacks.price);
	}
	
	fclose(file);
	lines = size;
	delete[] namesArr;
	delete[] producArr;
}

void addToBegining(FILE* file, packages fpacks, int& lines) {
	FILE *fileTmp;
	char ch;
	if ((file = fopen("file.txt", "r")) == NULL){ //Открываем файл и проверяем существует ли он
		printf("Файл для чтения не найден");
		exit(1);
	}

	if ((fileTmp = fopen("fileTmp.txt", "w+")) == NULL)	{ //Открываем файл и проверяем существует ли он
		printf("Файл для записи не найден");
		exit(1);
	}
	while ((ch = getc(file)) != EOF) //Переписываем из потока в переменную
		putc(ch, fileTmp);   //Теперь из переменной в временный файл

	fclose(file);
	fclose(fileTmp);

	file = fopen("file.txt", "w");

	if (file == NULL) exit(1);
	printf("Введите: наименование, производителя, кол-во и цену >> \n"); //Делаем запись, в пока что пустой файл
	scanf("%s", fpacks.title);    setbuf(stdin, NULL); // отключает буфер, то есть делает небуферизованный ввод
	scanf("%s", fpacks.producer); setbuf(stdin, NULL);
	scanf("%d", &fpacks.count);
	scanf("%lf", &fpacks.price);
	fprintf(file, "%-14s %-10s %-3d %.2lf\n", fpacks.title, fpacks.producer, fpacks.count, fpacks.price);
	fclose(file);

	if ((fileTmp = fopen("fileTmp.txt", "r")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для чтения не найден");
		exit(1);
	}

	if ((file = fopen("file.txt", "a")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Невозможно создать файл для записи");
		exit(1);
	}
	while ((ch = getc(fileTmp)) != EOF) //Переписываем из временного файла в основной
		putc(ch, file);

	fclose(fileTmp);
	fclose(file);
	
	lines++;
}

void addToEnd(FILE* file, packages fpacks, int& lines) {
	if ((file = fopen("file.txt", "a")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для добавления не найден");
		exit(1);
	}

	printf("Введите: наименование, производителя, кол-во и цену >> \n");
	scanf("%s", fpacks.title);    setbuf(stdin, NULL); // отключает буфер, то есть делает небуферизованный ввод
	scanf("%s", fpacks.producer); setbuf(stdin, NULL);
	scanf("%d", &fpacks.count);
	scanf("%lf", &fpacks.price);

	fprintf(file, "%-14s %-10s %-3d %.2lf\n", fpacks.title, fpacks.producer, fpacks.count, fpacks.price);
	fclose(file);

	lines++;
}

void printSelectedString(FILE* file, packages fpacks, int& lines) {
	int num = 0;
	printf("Какую строку распечатать >> ");	scanf_s("%d", &num);

	if (num > lines || num < 0) {
		printf("Такой строки нет!");
		exit(1);
	}
	if ((file = fopen("file.txt", "r")) == NULL) {  //Открываем файл и проверяем существует ли он
		printf("Файл для чтения не найден");
		exit(1);
	}
	for (int i = 0; i != num; i++) {             //Записываем строку из файла и перезаписываем до 'num'
		fscanf_s(file, "%s", fpacks.title, 40);             
		fscanf_s(file, "%s", fpacks.producer, 40);
		fscanf_s(file, "%d", &fpacks.count);
		fscanf_s(file, "%lf", &fpacks.price);
	}
	printf("\n%s %s %d %0.2lf\n", fpacks.title, fpacks.producer, fpacks.count, fpacks.price);
	fclose(file);
}

void printEntireFile(FILE* file, packages fpacks, int& lines){
	if ((file = fopen("file.txt", "r")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для чтения не найден");
		exit(1);
	}
	for (int i = 0; i != lines; i++) {
		fscanf_s(file, "%s", fpacks.title, 40);
		fscanf_s(file, "%s", fpacks.producer, 40);
		fscanf_s(file, "%d", &fpacks.count);
		fscanf_s(file, "%lf", &fpacks.price);
		printf("\n%-14s %-10s %-3d %.2lf\n", fpacks.title, fpacks.producer, fpacks.count, fpacks.price);
	}
	
	fclose(file);
}