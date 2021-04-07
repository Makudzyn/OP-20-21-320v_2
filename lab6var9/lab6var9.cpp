/*
	Рядки в стилі С.
Приклад 7
Написати функцію, яка визначає в рядку номер
позиції слова із заданим порядковим номером
*/

#include <iostream>
using namespace std;
int strleng(char* str) {
	for (char i; i != '\0';){
		i = (*str)++;
	}
}
/*
S - вхідний рядок
nom - порядковий номер слова
*/
int pozsl(char* str, int nom)
{
	int probel = 0;
	int poz = 0;
	while ((probel != nom - 1) && (*str != '\0'))
	{
		if (*str == ' ') probel++;
		str++;
		poz++;
	}
	return poz;
}

int main(){
	setlocale(LC_ALL, "ru");
	
	cout << "Введите предложение >> "; 
	char *str = new char(sizeof(char)*20);
	 gets_s();
	int nom;
	cout << "Введите порядковый номер слова nom -> ";
	cin >> nom;
	cout << "Номер позиции в предложении: ";
	cout << pozsl(str, nom) << endl;

	delete[] str;
}