#include "BMW.h"
BMW::BMW() {
	this->capacity = 100.0;
	this->consum = 8.5;
	this->spdRain = 190;
	this->spdSun = 250;
	this->spdSnow = 110;
}
double BMW::GetCapacity() {
	return this->capacity;
}
double BMW::GetConsum() {
	return this->consum;
}
int BMW::GetspdRain() {
	return this->spdRain;
}
int BMW::GetspdSun() {
	return this->spdSun;
}
int BMW::GetspdSnow() {
	return this->spdSnow;
}