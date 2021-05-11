#include <iostream>
using namespace std;

class Sum {
private:
	int sum, x, y;
public:
	Sum() { 
		x = 0;
		y = 0;
		sum = 0;
	}

	Sum(int vX, int vY) {
		x = vX;
		y = vY; 
		sum = x + y;
	}

	void set(int vX, int vY) {
		x = vX;
		y = vY;
	}

	void print() {
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "sum = " << sum << endl;
	}
	void sumOfNumbers() { sum = x + y; }
};

int main() {
	setlocale(LC_ALL, "ru");
	int x, y, point;

	cout << "Констуктор с параметрами\n\n";

	Sum var1(7, 5); 
	var1.print();
	cout << "Введите новые значения х и у >> \n";
	cin >> x; cin >> y;
	var1.set(x, y);
	var1.sumOfNumbers();
	var1.print();

	cout << "\nКонстуктор по умолчанию" << endl;

	Sum var2;
	Sum* ptr = &var2;
	ptr->print();
	cout << "Введите новые значения х и у >> \n";
	cin >> x; cin >> y;
	ptr->set(x, y);
	var2.sumOfNumbers();
	var2.print();


}

