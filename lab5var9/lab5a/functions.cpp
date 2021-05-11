#include "includes.h"

void printmas(int* mas, const int size) {
	for (int i = 0; i < size; i++) {
		printf(" %d ", *(mas + i));
	}
}

int* functionOfAll(int** arr, int* mas_min, int* mas_max, int size) {

	int* result = new int[2];
	
	for (int i = 0; i < size; i++) {
		int min = 100, max = 0;
		for (int j = 0; j < size; j++) {
			if (*(*(arr + j) + i) < min) {
				min = *(*(arr + j) + i);
			}
			if (*(*(arr + i) + j) > max) {
				max = *(*(arr + i) + j);
			}
		}
		*(mas_min + i) = min;
		*(mas_max + i) = max;
	}

	printf("\nMax >> ");
	for (int i = 0; i < size; i++) {printf("%3d", *(mas_max + i)); }

	printf("\nMin >> ");	
	for (int i = 0; i < size; i++) {printf("%3d", *(mas_min + i)); }
	printf("\n");

	int *mdSum, *sdComp;
	int sum = 0, composition = 1;
	mdSum = &sum; sdComp = &composition;

	for (int n = 0; n < size; n++) {
		*mdSum += *(*(arr + n) + n);
	}

	for (int n = 0, m = size - 1; n < size; n++, m--) {
		*sdComp *= *(*(arr + n) + m);
	}

	*result = *mdSum;
	*(result + 1) = *sdComp;

	return result;
}