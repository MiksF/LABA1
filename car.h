#pragma once
#include <fstream>
#include "Cargo_carrier.h"
#include "keeper.h"
using namespace std;

class Car : public Cargo_carrier {
private:
	int year;             //Год выпуска
	string marka; //Марка авто
	string model; //Модель авто
	string city1, city2, city3; //Города куда есть доставка
	int time1, time2, time3;    //Время доставки
	double volume;        //Объем перевозимого груза
public:
	Car();
	Car(int year, string marka, string model, string city1, string city2, string city3, int time1, int time2, int time3, double volume, Car& obj);
	~Car();
	Car(const Car&);
	void p() override;
	friend ofstream& operator << (ofstream& fout, Car& obj);
	friend ifstream& operator >> (ifstream& fin, Car& obj);
	friend ostream& operator << (ostream& out, Car& obj);
	friend istream& operator >> (istream& in, Car& obj);
	Car& operator =(const Car& other);
};