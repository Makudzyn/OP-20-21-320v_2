#include "includes.h"

void fileFilling(FILE* file,int const SIZE) {
	if ((file = fopen("file.dat", "wb")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для записи не найден");
		exit(1);
	}
	int rndNum;
	for (int i = 0; i < SIZE; i++) {  
		rndNum = rand() % 100 - 50;
		cout << setw(4) << rndNum;
		fwrite(&rndNum, sizeof(int), 1, file);
	}

	fclose(file);
}

int sumOf2n5n9(FILE* file, int& sum) {
	int number;
	int tmp[] = { 2, 5, 9 };
	if ((file = fopen("file.dat", "rb")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для записи не найден");
		exit(1);
	}

	for (int i = 0; i < 3; i++)	{
		fseek(file, *(tmp+i)*sizeof(int), SEEK_SET);
		fread(&number, sizeof(int), 1, file);
		sum += number;
	}
	return sum;
	fclose(file);
}

void findMin(FILE* file, int const SIZE, int& poz, int& min) {
	if ((file = fopen("file.dat", "rb")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для записи не найден");
		exit(1);
	}
	int num;
	fread(&min, sizeof(int), 1, file);
	for (int i = 0; i < SIZE; i++) {
		fread(&num, sizeof(int), 1, file);
		if (min > num) {
			min = num;
			poz = i+1;
		}
	}
	fclose(file);
}

void minChangeTo999(FILE* file, int const SIZE, int poz) {
	if ((file = fopen("file.dat", "r+b")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для записи не найден");
		exit(1);
	}

	fseek(file, poz * sizeof(int), SEEK_SET);
	int num = 999;
	fwrite(&num, sizeof(int), 1, file);

	fseek(file, 0, SEEK_SET);
	for (int i = 0; i < SIZE; i++) {
		fread(&num, sizeof(int), 1, file);
		cout << setw(4) << num;
	}

	fclose(file);
}