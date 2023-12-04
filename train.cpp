#include "train.h"
#include <iostream>
#include <string>
using namespace std;

Train::Train() {
	setlocale(LC_ALL, "Russian");
	cout << "����� ������������ �� ��������� ��� ������ Train" << endl << endl;
	name = "";
	year = 0;
	way = "";
	pastures = 0;
	volume = 0;
}

Train::Train(string name, int year, string way, int pastures, double volume, Train& obj) {
	setlocale(LC_ALL, "Russian");
	cout << "����� ������������ � ���������� ��� ������ Train" << endl << endl;
	obj.name = name;
	obj.year = year;
	obj.way = way;
	obj.pastures = pastures;
	obj.volume = volume;
}

Train::Train(const Train& other) {
	setlocale(LC_ALL, "Russian");
	cout << "����� ������������ ����������� ��� ������ Train" << endl << endl;
	*this = other;
}

Train::~Train() {
	setlocale(LC_ALL, "Russian");
	cout << "����� ����������� ��� ������ Train" << endl << endl;
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
	out << "������������: " << obj.name << endl;	
	out << "��� �������: " << obj.year << endl;
	out << "������ ������� ����������: " << obj.way << endl;
	out << "���������� �������: " << obj.pastures << endl;
	out << "����� ������������ �����: " << obj.volume << endl;
	return out;
}

istream& operator>>(istream& in, Train& obj) {
	setlocale(LC_ALL, "Russian");

	cout << "������� ������:" << endl << endl;
	cout << "������������: ";
	getchar();
	getline(cin, obj.name);

	while (1) {
		cout << "��� �������: ";
		cin >> obj.year;
		if (obj.year < 0 || obj.year > 2023) cout << "������������ ������!" << endl << endl;
		else break;
	}

	cout << "������ ������� ����������: ";
	getchar();
	getline(cin, obj.way);

	while (1) {
		cout << "���������� �������: ";
		cin >> obj.pastures;
		if (obj.pastures < 0) cout << "������������ ������!" << endl << endl;
		else break;
	}

	while (1) {
		cout << "����� ������������ �����: ";
		cin >> obj.volume;
		if (obj.volume < 0) cout << "������������ ������!!!" << endl << endl;
		else break;
	}

	return in;
}