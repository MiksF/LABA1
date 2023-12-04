#pragma once
#include <fstream>
#include "Cargo_carrier.h"
#include "keeper.h"
using namespace std;

class Airplane : public Cargo_carrier {
private:
	string type;          //���
	string name;          //������������
	double volume;        //����� ������������ �����
	string dimensions;    //��������
	string cities;        //������ ������� ��������
public:
	Airplane();
	Airplane(string type, string name, double volume, string dimensions, string cities, Airplane& obj);
	~Airplane();
	Airplane(const Airplane&);
	void p() override;
	friend ofstream& operator << (ofstream& fout, Airplane& obj);
	friend ifstream& operator >> (ifstream& fin, Airplane& obj);
	friend ostream& operator << (ostream& out, Airplane& obj);
	friend istream& operator >> (istream& in, Airplane& obj);
	Airplane& operator =(const Airplane& other);
};