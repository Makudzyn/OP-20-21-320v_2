#pragma once

//Кол-во чисел > предыдущего и < последующего и запись их во второй массив
void ArrSort(int size, int mass1[], int mass2[], int *pairElems, int *counter) { 
	for (int k = 1; k < size - 1; k++) {
		if ((mass1[k] > mass1[k - 1]) && (mass1[k] < mass1[k + 1])) {
			(*counter)++;
			if (mass1[k] % 2 == 0) {
				mass2[*pairElems] = mass1[k];
				(*pairElems)++;
			}
		}
	}
}



