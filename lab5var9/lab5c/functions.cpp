#include "includes.h"

void sortSelect(int* arr, int size, void (*Sort)(int*, int)){
	Sort(arr, size);
}

void bubbleSort(int* arr, int size) {
	int t, i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (*(arr + i) < *(arr + j)) {
				t = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = t;
			}
		}
	}
}

void gnomeSort(int* arr, int size) {
	int i = 1, j = 2;
	while (i < size) {
		if (*(arr + i - 1) <= *(arr + i)) {
			i = j; j++;
		}
		else {
			int t = *(arr + i);
			*(arr + i) = *(arr + i - 1);
			*(arr + i - 1) = t;
			i--;
			if (i == 0) {
				i = j;
				j++;
			}
		}
	}
}


void quickSort(int* numbers, int left, int right){    
	int pivot; 
	int l_hold = left; 
	int r_hold = right;
	pivot = *(numbers + left);
	while (left < right) {
		while ((*(numbers + right) >= pivot) && (left < right))
			right--; 
		if (left != right) 	{
			*(numbers + left) = *(numbers + right); 
			left++; 
		}
		while ((*(numbers + left) <= pivot) && (left < right))
			left++; 
		if (left != right) 	{
			*(numbers + right) = *(numbers + left); 
			right--; 
		}
	}
	*(numbers + left) = pivot; 
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) 
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}

void quick(int* arr, int size) {
	quickSort(arr, 0, size - 1);
}