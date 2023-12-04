#include <iostream>
#include "keeper.h"
#include "airplane.h"
#include "car.h"
#include "train.h"
#include "Cargo_carrier.h"
#include "menu.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Keeper <Airplane> airplane;
	Keeper <Car> car;
	Keeper <Train> train;
	int button;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "����: " << endl << endl;
		cout << "1 - ��������" << endl;
		cout << "2 - ������" << endl;
		cout << "3 - ������" << endl;
		cout << "0 - ���������� ������ ���������" << endl << endl;
		cout << "�������� �����: ";
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		switch (button) {
		case 1:
			menu(airplane, "airplane.txt");
			break;
		case 2:
			menu(car, "car.txt");
			break;
		case 3:
			menu(train, "train.txt");
			break;
		case 0:
			flag = false;
			cout << "\n���������� ������" << endl;
			break;
		default:
			cout << endl << "������� ������ �����!" << endl
				<< endl;
			system("pause");
			break;
		}
	}
	return 0;
}