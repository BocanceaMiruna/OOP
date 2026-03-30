#pragma once
#include "car.h"
class Seat : public car {
public:
	Seat();
	double GetCapacity() override;
	double GetConsum() override;
	int GetspdRain() override;
	int GetspdSnow() override;
	int GetspdSun() override;
};