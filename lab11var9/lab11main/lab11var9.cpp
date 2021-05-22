#include "includes.h"

class offPckgs{
private:
	string title;
	string producer;
	int count;
	double price;

public:

	void setOffPckgs(string t, string p, int c, double pr){
		title = t;
		producer = p;
		count = c;
		price = pr;
	}

	void getPackages(string t, string p, int c, double pr) {
		t = title;
		p = producer;
		c = count;
		pr = price;
	}

	void showPackages() {
		cout << "������������: " << title << endl;
		cout << "�������������: " << producer << endl;
		cout << "��� - ��: " << count << endl;
		cout << "����: " << price << endl;
	}

};

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int size;

	string titleTmp;
	string producerTmp;
	int countTmp;
	double priceTmp;
	cout << "������� ����� ���������?(1-10)" << endl; cin >> size;
	offPckgs pckgs[SIZE];

	cout << "\n������ �������\n";
	for (int i = 0; i < size; i++) {
		cout << "\n������������ >> "; cin >> titleTmp;
		cout << "\n������������� >> "; cin >> producerTmp;
		cout << "\n���-�� >> "; cin >> countTmp;
		cout << "\n���� >> "; cin >> priceTmp;
		pckgs[i].setOffPckgs(titleTmp, producerTmp, countTmp, priceTmp);
	}

	cout << "\n������ show\n";
	for (int i = 0; i < size; i++) {
		pckgs[i].showPackages();
		cout << "\n";
	}

	cout << "\n������ get � show\n";
	for (int i = 0; i < size; i++) {
		pckgs[i].getPackages(titleTmp, producerTmp, countTmp, priceTmp);
		pckgs[i].showPackages();
		cout << "\n";
	}

	return 0;
}