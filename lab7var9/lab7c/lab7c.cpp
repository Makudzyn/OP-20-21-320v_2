#include "includes.h"
#include "functions.h"


int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	FILE* file = {};
	int const SIZE = 20;
	int sum = 0, poz, min;

	cout << "Заполняем файл 20 случайными числами" << endl;
	fileFilling(file, SIZE);
	
	cout << "\n\nСумма 2, 5 и 9 числа в файле = "  << sumOf2n5n9(file, sum) << endl;

	findMin(file, SIZE, poz, min);

	cout << "\nНаименьшее число = " << min << endl;
	cout << "Находится на " << poz << " позиции\n" << endl;

	cout << "Заменяем минимальное на 999" << endl;
	minChangeTo999(file, SIZE, poz);
	cout << endl;
	return 0;
}