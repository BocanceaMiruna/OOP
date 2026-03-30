#include "Seat.h"
Seat::Seat() {
	this->capacity = 90.0;
	this->consum = 5.5;
	this->spdRain = 170;
	this->spdSun = 200;
	this->spdSnow = 90;
}
double Seat::GetCapacity() {
	return this->capacity;
}
double Seat::GetConsum() {
	return this->consum;
}
int Seat::GetspdRain() {
	return this->spdRain;
}
int Seat::GetspdSun() {
	return this->spdSun;
}
int Seat::GetspdSnow() {
	return this->spdSnow;
}