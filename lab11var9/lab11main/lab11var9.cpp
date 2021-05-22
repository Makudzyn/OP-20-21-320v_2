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
		cout << "Наименование: " << title << endl;
		cout << "Производитель: " << producer << endl;
		cout << "Кол - во: " << count << endl;
		cout << "Цена: " << price << endl;
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
	cout << "Сколько строк заполнять?(1-10)" << endl; cin >> size;
	offPckgs pckgs[SIZE];

	cout << "\nРабота сеттера\n";
	for (int i = 0; i < size; i++) {
		cout << "\nНаименование >> "; cin >> titleTmp;
		cout << "\nПроизводитель >> "; cin >> producerTmp;
		cout << "\nКол-во >> "; cin >> countTmp;
		cout << "\nЦена >> "; cin >> priceTmp;
		pckgs[i].setOffPckgs(titleTmp, producerTmp, countTmp, priceTmp);
	}

	cout << "\nРабота show\n";
	for (int i = 0; i < size; i++) {
		pckgs[i].showPackages();
		cout << "\n";
	}

	cout << "\nРабота get и show\n";
	for (int i = 0; i < size; i++) {
		pckgs[i].getPackages(titleTmp, producerTmp, countTmp, priceTmp);
		pckgs[i].showPackages();
		cout << "\n";
	}

	return 0;
}