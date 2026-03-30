#include "RangeRover.h"
RangeRover::RangeRover() {
	this->capacity = 120.0;
	this->consum = 10.5;
	this->spdRain = 90;
	this->spdSun = 150;
	this->spdSnow = 140;
}
double RangeRover::GetCapacity() {
	return this->capacity;
}
double RangeRover::GetConsum() {
	return this->consum;
}
int RangeRover::GetspdRain() {
	return this->spdRain;
}
int RangeRover::GetspdSun() {
	return this->spdSun;
}
int RangeRover::GetspdSnow() {
	return this->spdSnow;
}