#pragma once
#include <fstream>
#include "Cargo_carrier.h"
#include "keeper.h"
using namespace std;

class Train : public Cargo_carrier {
private:
	string name;          //������������
	int year;             //��� �������
	string way;           //������ ������� ����������
	int pastures;         //���������� �������
	double volume;        //����� ������������ �����
public:
	Train();
	Train(string name, int year, string way, int pastures, double volume, Train& obj);
	~Train();
	Train(const Train&);
	void p() override;
	friend ofstream& operator << (ofstream& fout, Train& obj);
	friend ifstream& operator >> (ifstream& fin, Train& obj);
	friend ostream& operator << (ostream& out, Train& obj);
	friend istream& operator >> (istream& in, Train& obj);
	Train& operator =(const Train& other);
};