#include "includes.h"

void massFillingAndPrintin(int* mas1, int const SIZE) {
	for (int i = 0; i < SIZE; i++) {
		*(mas1 + i) = rand() % 25 + 1;
		cout << setw(4) << *(mas1 + i);
	}
}

void fileFilling(FILE* file, int* mas1, int const SIZE) {
	if ((file = fopen("f1.dat", "wb")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для записи не найден");
		exit(1);
	}

	fwrite(mas1, sizeof(int), SIZE, file);

	fclose(file);
}

void fileWorking(FILE* file,int* mas2, int const SIZE) {
	if ((file = fopen("f1.dat", "rb")) == NULL) { //Открываем файл и проверяем существует ли он
		printf("Файл для записи не найден");
		exit(1);
	}
	
	for (int i = 0; i != SIZE; i++)	{
		fread((mas2 + i), sizeof(int), 1, file);
	}
	fclose(file);
}

int sumOfNums(int* mas2, int const SIZE) {

	int sum = 0;
	for (int i = 0; i != SIZE; i++){
		if (*(mas2 + i) % 2 == 0) {
			sum += *(mas2 + i);
		}
	}
	
	return sum;
}