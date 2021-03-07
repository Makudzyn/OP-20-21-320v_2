#include "functions.h"

void chekerOfDefine(int const size, int* mass, int** mass1) {
#ifdef CHOICE
	odArrayWork(size, mass);
#else
	tdArrayWork(size, mass1);
#endif // CHOICE
}
void odArrayWork(int const size, int* mass) {
	int rows = size - 1, cols = 0, k = 0;
	for (int i = 0; i < size; i++) {                // 8 0 | 8 1 | 7 0 | 8 2 | 7 1 | 6 0 | 8 3 | 7 2 | 6 1 | 5 0 |
		for (int j = 0; j < size; j++) {
			k++;
			*(mass + rows * size + cols) = k;
			int rowsTmp = rows, colsTmp = cols;

			if (rows != 0 && cols != 0) {                  //Проверка дохождения до границы
				rows--; cols--;
			}
			else if (rows == 0 && cols == 0) {             //Переход через середину, случай попадания в (0,0)
				rows = size - 2;
				cols = size - 1;
			}
			else if (cols == 0) {                          //Переход столбцов
				rows = size - 1;
				cols = size - rowsTmp;
			}
			else if (rows == 0) {                         //Переход строк
				rows = size - 2 - colsTmp;
				cols = size - 1;
			}
		}

	}
}
void tdArrayWork(int const size, int** mass1) {
	int rows = size - 1, cols = 0, k = 0;
	for (int i = 0; i < size; i++)
		*(mass1 + i) = new int[size];

	for (int i = 0; i < size; i++) {                // 8 0 | 8 1 | 7 0 | 8 2 | 7 1 | 6 0 | 8 3 | 7 2 | 6 1 | 5 0 |
		for (int j = 0; j < size; j++) {
			k++;
			*(*(mass1 + rows) + cols) = k;
			int rowsTmp = rows, colsTmp = cols;

			if (rows != 0 && cols != 0) {                  //Проверка дохождения до границы
				rows--; cols--;
			}
			else if (rows == 0 && cols == 0) {             //Переход через середину, случай попадания в (0,0)
				rows = size - 2;
				cols = size - 1;
			}
			else if (cols == 0) {                          //Переход столбцов
				rows = size - 1;
				cols = size - rowsTmp;
			}
			else if (rows == 0) {                         //Переход строк
				rows = size - 2 - colsTmp;
				cols = size - 1;
			}
		}
	}

}
void printWithDefine(int const size, int* mass, int** mass1) {
#ifdef CHOICE
	for (int i = 0; i < size; i++) {                    //Вывод одномерного массива
		for (int j = 0; j < size; j++) {
			cout << setw(4) << *(mass + i * size + j);
		}
		cout << "\n\n";
	}
#else
	for (int i = 0; i < size; i++) {                    //Вывод двумерного массива
		for (int j = 0; j < size; j++) {
			cout << setw(4) << *(*(mass1 + i) + j);
		}
		cout << "\n\n";
	}

#endif // CHOICE

}
void clear(int* mass, int** mass1, int size) {
	//Очистка памяти
	for (int i = 0; i < size; i++)
		delete[] * (mass1 + i);
	delete[] mass;
}

