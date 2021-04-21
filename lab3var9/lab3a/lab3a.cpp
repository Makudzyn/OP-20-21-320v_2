#include "includes.h"
#include "functions.h"

int main() {

	setlocale(LC_ALL, "ru");
	/*srand(time(0));*/

	int* ptr;                // ��������� �� ������� �������
	int** ptrPointer;        // ��������� �� ���������
	int sum = 0, amountOfNeg = 0, check, size;

	cout << "������� ������ ������� >> " ;	cin >> size;

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
		case 1: //������������� �����
			for (int i = 0; i < size; i++) {
				if (*(ptr + i) < 0) {
					sum += *(ptr + i);
					amountOfNeg++;
				}
			}

			cout << "����� ������������� " << sum << endl;
			cout << "���-�� ������������� " << amountOfNeg << endl;
			break;

		case 2: //����� ���������� ����c
			for (int i = 0; i < size; i++, ptr++) {
				if (*ptr < 0) {
					sum += *ptr;
					amountOfNeg++;
				}
			}

			cout << "����� ������������� " << sum << endl;
			cout << "���-�� ������������� " << amountOfNeg << endl;
			break;

		case 3: //�� ��������� ���������
			for (; ptr < mass + size; ptr++) {
				if (*ptr < 0) {
					sum += *ptr;
					amountOfNeg++;
				}
			}

			cout << "����� ������������� " << sum << endl;
			cout << "���-�� ������������� " << amountOfNeg << endl;
			break;

		case 4: //����� ������ ����������
			for (int i = 0; i < size; i++) {
				*(massPtr + i) = (mass + i);          
				if (**(massPtr + i) < 0) {         
					sum += **(massPtr + i);
					amountOfNeg++;
				}
			}

			cout << "����� ������������� " << sum << endl;
			cout << "���-�� ������������� " << amountOfNeg << endl;
			break;

		case 5: //����� ��������� �� ���������
			ptrPointer = &ptr;
			for (int i = 0; i < size; i++, (*ptrPointer)++) {
				if (**ptrPointer < 0) {
					sum += **ptrPointer;
					amountOfNeg++;
				}
			}

			cout << "����� ������������� " << sum << endl;
			cout << "���-�� ������������� " << amountOfNeg << endl;
			break;

		case 6://� ���� ������� � ����������� �����������
			sumOfNegative(mass, &sum, &amountOfNeg, size);

			cout << "����� ������������� " << sum << endl;
			cout << "���-�� ������������� " << amountOfNeg << endl;
			break;

		default:
			cout << "Something went wrong...";
			break;
		}

		delete[] mass;
		delete[] massPtr;
		return 0;
}
