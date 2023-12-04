#include "airplane.h"
#include <iostream>
#include <string>
using namespace std;

Airplane::Airplane() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора по умолчанию для класса Airplane" << endl << endl;
	type = "";
	name = "";
	volume = 0;
	dimensions = "";
	cities = "";
}

Airplane::Airplane(string type, string name, double volume, string dimensions, string cities, Airplane& obj) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора с параметром для класса Airplane" << endl << endl;
	obj.type = type;
	obj.name = name;
	obj.volume = volume;
	obj.dimensions = dimensions;
	obj.cities = cities;
}


Airplane::Airplane(const Airplane& other) {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов конструктора копирования для класса Airplane" << endl << endl;
	*this = other;
}

Airplane::~Airplane() {
	setlocale(LC_ALL, "Russian");
	cout << "Вызов деструктора для класса Airplane" << endl << endl;
}

void Airplane::p() {
	cin >> *this;
}

Airplane& Airplane::operator=(const Airplane& other) {
	this->type = other.type;
	this->name = other.name;
	this->volume = other.volume;
	this->dimensions = other.dimensions;
	this->cities = other.cities;
	return *this;
}

ofstream& operator<<(ofstream& fout, Airplane& obj) {
	fout << obj.type << " " << endl;
	fout << obj.name << " " << endl;
	fout << obj.volume << " " << endl;
	fout << obj.dimensions << " " << endl;
	fout << obj.cities << " " << endl;
	fout << endl;
	return fout;
}

ifstream& operator>>(ifstream& fin, Airplane& obj) {
	fin >> obj.type >> obj.name >> obj.volume >> obj.dimensions >> obj.cities;
	return fin;
}

ostream& operator<<(ostream& out, Airplane& obj) {
	setlocale(LC_ALL, "Russian");
	out << "Тип самолета: " << obj.type << endl;
	out << "Наименования: " << obj.name << endl;
	out << "Объем перевозимого груза: " << obj.volume << endl;
	out << "Габариты: " << obj.dimensions << endl;
	out << "Посещаемые города: " << obj.cities << endl;
	return out;
}

istream& operator>>(istream& in, Airplane& obj) {
	setlocale(LC_ALL, "Russian");

	cout << "Введите данные:" << endl << endl;
	cout << "Тип самолета: ";
	getchar();
	getline(cin, obj.type);
	cout << "Наименовани: ";
	getchar();
	getline(cin, obj.name);

	while (1) {
		cout << "Объем перевозимого груза: ";
		cin >>obj.volume;
		if (obj.volume < 0) cout << "Некорректные данные!!!" << endl << endl;
		else break;
	}

	cout << "Габариты: ";
	getchar();
	getline(cin, obj.dimensions);
	cout << "Посещаемые города: ";
	getchar();
	getline(cin, obj.cities);
	return in;
}