#include "functions.h"

int main() {
	srand(time(0));
	setlocale(LC_ALL, "ru");
	int const N = 100;
	int mainArr[N], minusArr[N];
	int nullArr[N], plusArr[N];
	int mainSize, size1 = 0, size2 = 0, size3 = 0;
	
	cout << "¬ведите размер массива >> "; cin >> mainSize;

	arrFilling(mainSize, mainArr, minusArr, plusArr, nullArr, &size1, &size2, &size3);
	mainFilling(mainArr, nullArr, plusArr, minusArr, size1, size2, size3);
	

	cout << "\n»тоговый массив : ";
	for (int i = 0; i < mainSize; i++)
		cout << setw(4) << mainArr[i];

}

