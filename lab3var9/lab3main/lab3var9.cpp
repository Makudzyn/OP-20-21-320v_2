/*В целочисленном массиве определить количество элементов, которые больше предыдущего элемента,
но меньше последующего.Переписать в новый массив все четные элементы. */

#include "includes.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	int size, counter = 0, pairElems = 0;
	cout << "Введите размер массива >> "; cin >> size; 

	//int* mass1 = (int*)malloc(size * sizeof(int));
	//int* mass2 = (int*)malloc(size * sizeof(int));
	int* mass1 = new int[size * sizeof(int)];
	int* mass2 = new int[size * sizeof(int)];

	for (int i = 0; i < size; i++) 
		mass1[i] = rand() % 100 - 25;

	ArrSort(size, mass1, mass2, &pairElems, &counter);

	cout << "\nПервый массив :";
	for (int i = 0; i < size; i++) 
		cout << setw(4) << mass1[i];

	cout << "\n\nКол-во чисел > предыдущего и < последующего : " << counter << endl;

	cout << "\nЧетные елементы, которые > предыдущего и < последующего : ";
	if (pairElems != 0)	{
		for (int i = 0; i < pairElems; i++)
			cout << setw(4) << mass2[i];
	}
	else{
		cout << "Нет ни одного елемента, который бы удовлетворял условию\n";
	}
	

	cout << endl;
	delete mass1;
	delete mass2;
	/*free(mass1);
	free(mass2);*/





}