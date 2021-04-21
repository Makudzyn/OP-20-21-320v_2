#include "includes.h"
#include "functions.h"

int main() {

	setlocale(LC_ALL, "ru");
	/*srand(time(0));*/

	int* ptr;                // указатель на элемент массива
	int** ptrPointer;        // указатель на указатель
	int sum = 0, amountOfNeg = 0, check, size;

	cout << "Введите размер массива >> " ;	cin >> size;

	int* mass = new int[size];         
	int** massPtr = new int* [size];  


	for (int i = 0; i < size; i++)
		*(mass + i) = rand() % 100 - 25;

	for (int i = 0; i < size; i++)
		cout << setw(4) << *(mass + i);

	cout << endl << endl;

	menu(); cin >> check;

	ptr = mass;
	cout << mass;
		switch (check){
		case 1: //относительный адрес
			for (int i = 0; i < size; i++) {
				if (*(ptr + i) < 0) {
					sum += *(ptr + i);
					amountOfNeg++;
				}
			}

			cout << "Сумма отрицательных " << sum << endl;
			cout << "Кол-во отрицательных " << amountOfNeg << endl;
			break;

		case 2: //через абсолютный адреc
			for (int i = 0; i < size; i++, ptr++) {
				if (*ptr < 0) {
					sum += *ptr;
					amountOfNeg++;
				}
			}

			cout << "Сумма отрицательных " << sum << endl;
			cout << "Кол-во отрицательных " << amountOfNeg << endl;
			break;

		case 3: //не используя адресацию
			for (; ptr < mass + size; ptr++) {
				if (*ptr < 0) {
					sum += *ptr;
					amountOfNeg++;
				}
			}

			cout << "Сумма отрицательных " << sum << endl;
			cout << "Кол-во отрицательных " << amountOfNeg << endl;
			break;

		case 4: //через массив указателей
			for (int i = 0; i < size; i++) {
				*(massPtr + i) = (mass + i);          
				if (**(massPtr + i) < 0) {         
					sum += **(massPtr + i);
					amountOfNeg++;
				}
			}

			cout << "Сумма отрицательных " << sum << endl;
			cout << "Кол-во отрицательных " << amountOfNeg << endl;
			break;

		case 5: //через указатель на указатель
			ptrPointer = &ptr;
			for (int i = 0; i < size; i++, (*ptrPointer)++) {
				if (**ptrPointer < 0) {
					sum += **ptrPointer;
					amountOfNeg++;
				}
			}

			cout << "Сумма отрицательных " << sum << endl;
			cout << "Кол-во отрицательных " << amountOfNeg << endl;
			break;

		case 6://в виде функции с параметрами указателями
			sumOfNegative(mass, &sum, &amountOfNeg, size);

			cout << "Сумма отрицательных " << sum << endl;
			cout << "Кол-во отрицательных " << amountOfNeg << endl;
			break;

		default:
			cout << "Something went wrong...";
			break;
		}

		delete[] mass;
		delete[] massPtr;
		return 0;
}
