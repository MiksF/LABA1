#include "train.h"
#include <iostream>
#include <string>
using namespace std;

Train::Train() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора по умолчанию для класса Train" << endl << endl;
	name = "";
	year = 0;
	way = "";
	pastures = 0;
	volume = 0;
}

Train::Train(string name, int year, string way, int pastures, double volume, Train& obj) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора с параметром для класса Train" << endl << endl;
	obj.name = name;
	obj.year = year;
	obj.way = way;
	obj.pastures = pastures;
	obj.volume = volume;
}

Train::Train(const Train& other) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора копирования для класса Train" << endl << endl;
	*this = other;
}

Train::~Train() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов деструктора для класса Train" << endl << endl;
}

void Train::p() {
	cin >> *this;
}

Train& Train::operator=(const Train& other) {
	this->name = other.name;
	this->year = other.year;
	this->way = other.way;
	this->pastures = other.pastures;
	this->volume = other.volume;
	return *this;
}

ofstream& operator<<(ofstream& fout, Train& obj) {
	fout << obj.name << " " << endl;
	fout << obj.year << " " << endl;
	fout << obj.way << " " << endl;
	fout << obj.pastures << " " << endl;
	fout << obj.volume << " " << endl;
	fout << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Train& obj) {
	fin >> obj.name >> obj.year >> obj.way >> obj.pastures >> obj.volume;
	return fin;
}

ostream& operator<<(ostream& out, Train& obj) {
	setlocale(LC_ALL, "Russian");
	out << "Наименование: " << obj.name << endl;	
	out << "Год выпуска: " << obj.year << endl;
	out << "Полный маршрут следования: " << obj.way << endl;
	out << "Количество вагонов: " << obj.pastures << endl;
	out << "Объем перевозимого груза: " << obj.volume << endl;
	return out;
}

istream& operator>>(istream& in, Train& obj) {
	setlocale(LC_ALL, "Russian");

	cout << "Введите данные:" << endl << endl;
	cout << "Наименование: ";
	getchar();
	getline(cin, obj.name);

	while (1) {
		cout << "Год выпуска: ";
		cin >> obj.year;
		if (obj.year < 0 || obj.year > 2023) cout << "Некорректные данные!" << endl << endl;
		else break;
	}

	cout << "Полный маршрут следования: ";
	getchar();
	getline(cin, obj.way);

	while (1) {
		cout << "Количество вагонов: ";
		cin >> obj.pastures;
		if (obj.pastures < 0) cout << "Некорректные данные!" << endl << endl;
		else break;
	}

	while (1) {
		cout << "Объем перевозимого груза: ";
		cin >> obj.volume;
		if (obj.volume < 0) cout << "Некорректные данные!!!" << endl << endl;
		else break;
	}

	return in;
}