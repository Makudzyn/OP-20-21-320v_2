#include "functions.h"

int main() {

	setlocale(LC_ALL, "ru");
	int size;
	cout << "Введите N размер матрицы(N*N)>> "; cin >> size;

	int* mass = new int[size * size * sizeof(int)]; 
	int** mass1 = new int* [size * sizeof(int)];

	chekerOfDefine(size, mass, mass1); /*Делаем выбор в зависимости от наличия или отсутсвия макроса 
	и тут же делаем преобразования в матрице*/

	printWithDefine(size, mass, mass1); //Выводим ОМ или ДМ(от макроса)

	clear(mass, mass1, size); //Убираем за собой
}