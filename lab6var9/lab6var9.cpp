/*
	����� � ���� �.
������� 7
�������� �������, ��� ������� � ����� �����
������� ����� �� ������� ���������� �������
*/

#include <iostream>
using namespace std;
int strleng(char* str) {
	for (char i; i != '\0';){
		i = (*str)++;
	}
}
/*
S - ������� �����
nom - ���������� ����� �����
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
	
	cout << "������� ����������� >> "; 
	char *str = new char(sizeof(char)*20);
	 gets_s();
	int nom;
	cout << "������� ���������� ����� ����� nom -> ";
	cin >> nom;
	cout << "����� ������� � �����������: ";
	cout << pozsl(str, nom) << endl;

	delete[] str;
}