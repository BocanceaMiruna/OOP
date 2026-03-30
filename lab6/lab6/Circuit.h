#pragma once
#include "weather.h"
#include "car.h"
class Circuit {
	int length;
	Weather weather;
	car *cars[25];
	int carcnt;
	struct Results {
		car *drv;
		double time;
		bool finish;
	};
	Results res[25];
public:
	Circuit();
	~Circuit();
void setLength(int len);
void setWeather(Weather weather);
void AddCar(car* c);
void Race();
void ShowFinalRanks();
void DNF();//did not finish
};