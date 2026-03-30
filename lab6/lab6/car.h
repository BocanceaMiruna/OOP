#pragma once
#include "weather.h"
#include "tires.h"
#include "Driver.h"
class car {
protected:
	double capacity=0;
	double consum=0;
	int spdRain=0;
	int spdSun=0;
	int spdSnow=0;
//bonus:
	Driver* driver;
	TypeTires tires;
public:
	car():driver(nullptr),tires(TypeTires::Slicks){}
	void SetDriver(Driver* d) { this->driver = d; }
	void SetTires(TypeTires t) { this->tires = t; }

	Driver* GetDriver() { return this->driver; }
	TypeTires GetTires() { return this->tires; }
	virtual double GetCapacity() = 0;
	virtual double GetConsum() = 0;
	virtual int GetspdRain() = 0;
	virtual int GetspdSun() = 0;
	virtual int GetspdSnow() = 0;
	virtual ~car()=default;
};