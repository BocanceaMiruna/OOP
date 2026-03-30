#pragma once
#include "car.h"
class Fiat: public car {
public:
	Fiat();
	double GetCapacity() override;
	double GetConsum() override;
	int GetspdRain() override;
	int GetspdSnow() override;
	int GetspdSun() override;
};