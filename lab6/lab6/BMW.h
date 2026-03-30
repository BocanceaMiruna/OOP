#pragma once
#include "car.h"
class BMW : public car {
public:
	BMW();
	double GetCapacity() override;
	double GetConsum() override;
	int GetspdRain() override;
	int GetspdSnow() override;
	int GetspdSun() override;
};