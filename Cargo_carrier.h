#pragma once
#include <fstream>
#include "Cargo_carrier.h"
#include "keeper.h"
using namespace std;

class Cargo_carrier {
public:
	Cargo_carrier();
	virtual ~Cargo_carrier();
	virtual void p() = 0;
};