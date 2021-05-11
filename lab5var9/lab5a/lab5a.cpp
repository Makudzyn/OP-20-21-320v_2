#include "includes.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int* mdSum, *sdComp;
	int size;

	printf("Введите размер массива >> ");
	scanf_s("%d", &size);

	int* minArr = new int[size];
	int* maxArr = new int[size];
	int** arr = new int*[size];

	for (int i = 0; i < size; i++)	{
		*(arr+i) = new int[size];
	}

	printf("Двумерный массив >> \n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			*(*(arr + i) + j) = rand() % 100;
			printf("%3d", *(*(arr + i) + j));
		}
		printf("\n");
	}

	int* mainFoo = functionOfAll(arr, minArr, maxArr, size);

	printf("Сумма на ГД в одномерном массиве >> %d\n", *mainFoo);
	printf("Произведение на ПД в одномерном массиве >> %d", *(mainFoo + 1));


	for (int i = 0; i < size; i++) {
		delete *(arr+i);
	}
	delete[] arr;
	delete[] minArr;
	delete[] maxArr;
	delete[] mainFoo;

	return 0;
}