#include "functions.h"


int main(){
    srand(time(0));
    setlocale(LC_ALL, "ru");

    int size;
    cout << "Введите размер массива >> "; cin >> size;
    int* mass = new int[size * sizeof(int)];

    for (int i = 0; i < size; i++) {
        *(mass + i) = rand() % 60 - 25;
        cout << setw(4) << *(mass + i);
    }
    cout << "\n\n";

    int(*fooPtr)(int const size, int* mass);

    fooPtr = fooSlct;

    menu();
    cout << fooPtr(size, mass);

    delete[] mass;
}

