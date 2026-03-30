#pragma once
#include "car.h"
class Volvo : public car {
public:
	Volvo();
	double GetCapacity() override;
	double GetConsum() override;
	int GetspdRain() override;
	int GetspdSnow() override;
	int GetspdSun() override;
};