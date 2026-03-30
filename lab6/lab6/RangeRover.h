#pragma once
#include "car.h"
class RangeRover : public car {
public:
	RangeRover();
	double GetCapacity() override;
	double GetConsum() override;
	int GetspdRain() override;
	int GetspdSnow() override;
	int GetspdSun() override;
};