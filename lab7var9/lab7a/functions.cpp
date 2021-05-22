#include "includes.h"

void arrWorking(int* mas1, int const SIZE) {
	srand(time(0));
	for (int i = 0; i < SIZE; i++)	{
		*(mas1 + i) = rand() % 25 + 1;
		cout << setw(4) << *(mas1 + i);
	}
}

void fromArrToFile1(FILE* file1, int* mas1, int const SIZE) {
	if ((file1 = fopen("f1.txt", "w")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для записи не найден");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++)	{
		fprintf(file1, "%4d\n", *(mas1 + i));
	}
	fclose(file1);
}

void fromFileToArrAndFile2(FILE* file1, FILE* file2, int* mas1, int* mas2, int const SIZE) {
	if ((file1 = fopen("f1.txt", "r")) == NULL) { //Открываем файл1 и проверяем существует ли он
		printf("Файл для чтения не найден");
		exit(1);
	}
	if ((file2 = fopen("f2.txt", "w")) == NULL) { //Открываем файл2 и проверяем существует ли он
		printf("Файл для записи не найден");
		exit(1);
	}

	for (int i = 0; i < SIZE; i++){
		fscanf_s(file1, "%d", &*(mas2 + i));
		fprintf(file2, "%4d\n", *(mas2 + i));
	}

	fclose(file1);
	fclose(file2);
}

void file2Print(FILE* file2, int& x, int const SIZE) {
	if ((file2 = fopen("f2.txt", "r")) == NULL) { //Открываем файл2 и проверяем существует ли он
		printf("Файл для записи не найден");
		exit(1);
	}

	fseek(file2, 0, SEEK_SET);
	for (int i = 0; i < SIZE; i++)	{
		fscanf_s(file2, "%d", &x);
		cout << "x = " << x << "\t";
	}

	fclose(file2);
}