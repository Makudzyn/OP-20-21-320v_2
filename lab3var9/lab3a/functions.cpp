#include "includes.h"

void sumOfNegative(int* mass, int* sum, int* neg, int size) {
	for (int i = 0; i < size; i++) {
		if (*(mass + i) < 0) {
			*sum += *(mass + i);
			(*neg)++;
		}
	}
}

void menu() {
	cout << "Каким способом вы хотите найти сумму отрицательных чисел?" << endl << endl;
	cout << "1 - Через относительный адрес" << endl;
	cout << "2 - Через абсолютный адрес " << endl;
	cout << "3 - Без использования индексации " << endl;
	cout << "4 - Используя массив указателей " << endl;
	cout << "5 - Через указатель на указатель " << endl;
	cout << "6 - В виде функции с указателями в параметрах " << endl;
	cout <<">> ";

}