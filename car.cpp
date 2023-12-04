#include "car.h"
#include <iostream>
#include <string>
using namespace std;

Car::Car() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора по умолчанию для класса Car" << endl << endl;
	year = 0;
	marka = "";
	model = "";
	city1 = city2 = city3 = "";
	time1 = time2 = time3 = 0;
	volume = 0;
}

Car::Car(int year, string marka, string model, string city1, string city2, string city3, int time1, int time2, int time3, double volume, Car& obj) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора с параметром для класса Car" << endl << endl;
	obj.year = year;
	obj.marka = marka;
	obj.model = model;
	obj.city1 = city1;
	obj.city2 = city2;
	obj.city3 = city3;

	obj.time1 = time1;
	obj.time2 = time2;
	obj.time3 = time3;

	obj.volume = volume;
}

Car::Car(const Car& other) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора копирования для класса Car" << endl << endl;
	*this = other;
}

Car::~Car() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов деструктора для класса Car" << endl << endl;
}

void Car::p() {
	cin >> *this;
}

Car& Car::operator=(const Car& other) {
	this->year = other.year;
	this->marka = other.marka;
	this->model = other.model;

	this->city1 = other.city1;
	this->city2 = other.city2;
	this->city3 = other.city3;

	this->time1 = other.time1;
	this->time2 = other.time2;
	this->time3 = other.time3;

	this->volume = other.volume;
	return *this;
}

ofstream& operator<<(ofstream& fout, Car& obj) {
	fout << obj.year << " " << endl;
	fout << obj.marka << " " << endl;
	fout << obj.model << " " << endl;

	fout << obj.city1 << " " << endl;
	fout << obj.city2 << " " << endl;
	fout << obj.city3 << " " << endl;

	fout << obj.time1 << " " << endl;
	fout << obj.time2 << " " << endl;
	fout << obj.time3 << " " << endl;

	fout << obj.volume << " " << endl;
	fout << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Car& obj) {
	fin >> obj.year >> obj.marka >> obj.model >> obj.city1 >> obj.city2 >> obj.city3 >> obj.time1 >> obj.time2 >> obj.time3 >> obj.volume;
	return fin;
}

ostream& operator<<(ostream& out, Car& obj) {
	setlocale(LC_ALL, "Russian");
	out << "Год выпуска: " << obj.year << endl;

	out << "Марка машины: " << obj.marka << endl;
	out << "Модель машины: " << obj.model << endl;

	out << "Город где есть доставка: " << obj.city1 << endl;
	out << "Время доставки: " << obj.time1 << endl;

	out << "Город где есть доставка: " << obj.city2 << endl;
	out << "Время доставки: " << obj.time2 << endl;

	out << "Город где есть доставка: " << obj.city3 << endl;
	out << "Время доставки: " << obj.time3 << endl;


	out << "Объем перевозимого груза: " << obj.volume << endl;
	return out;
}

istream& operator>>(istream& in, Car& obj) {
	setlocale(LC_ALL, "Russian");


	while (1) {
		cout << "Год выпуска: ";
		cin >> obj.year;
		if (obj.year < 0 || obj.year > 2023) cout << "Некорректные данные!" << endl << endl;
		else break;
	}

	cout << "Марка машины: ";
	getchar();
	getline(cin, obj.marka);

	cout << "Модель машины: ";
	getchar();
	getline(cin, obj.model);

	cout << "Город где есть доставка: ";
	getchar();
	getline(cin, obj.city1);
	while (1) {
		cout << "Время доставки: ";
		cin >> obj.time1;
		if (obj.time1 < 0) cout << "Некорректные данные!" << endl << endl;
		else break;
	}

	cout << "Город где есть доставка: ";
	getchar();
	getline(cin, obj.city2);
	while (1) {
		cout << "Время доставки: ";
		cin >> obj.time2;
		if (obj.time2 < 0) cout << "Некорректные данные!" << endl << endl;
		else break;
	}

	cout << "Город где есть доставка: ";
	getchar();
	getline(cin, obj.city3);
	while (1) {
		cout << "Время доставки: ";
		cin >> obj.time3;
		if (obj.time3 < 0) cout << "Некорректные данные!" << endl << endl;
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