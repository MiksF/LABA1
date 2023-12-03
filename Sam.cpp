#include "Sam.h"
#include <iostream>
#include <string>
using namespace std;

Airplane::Airplane() {
	setlocale(LC_ALL, "Russian");
	cout << "����� ������������ �� ��������� ��� ������ Airplane" << endl << endl;
	type = "";
	name = "";
	volume = "";
	dimensions = "";
	cities = "";
}

Airplane::Airplane(const Airplane& other) {
	setlocale(LC_ALL, "Russian");
	cout << "����� ������������ ����������� ��� ������ Airplane" << endl << endl;
	*this = other;
}

Airplane::~Airplane() {
	setlocale(LC_ALL, "Russian");
	cout << "����� ����������� ��� ������ Airplane" << endl << endl;
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
	out << "��� ��������: " << obj.type << endl;
	out << "������������: " << obj.name << endl;
	out << "����� ������������ �����: " << obj.volume << endl;
	out << "��������: " << obj.dimensions << endl;
	out << "���������� ������: " << obj.cities << endl;
	return out;
}

istream& operator>>(istream& in, Airplane& obj) {
	setlocale(LC_ALL, "Russian");

	cout << "������� ������:" << endl << endl;
	cout << "��� ��������: ";
	getchar();
	getline(cin, obj.type);
	cout << "�����������: ";
	getchar();
	getline(cin, obj.name);

	while (1) {
		cout << "����� ������������ �����: ";
		getchar();
		getline(cin, obj.volume);
		if (cin.fail() || obj.volume < 0) {
			cout << "������������ ������!!!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
	}

	cout << "��������: ";
	getchar();
	getline(cin, obj.dimensions);
	cout << "���������� ������: ";
	getchar();
	getline(cin, obj.cities);
	return in;
}