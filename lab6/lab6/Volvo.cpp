#include "Volvo.h"
Volvo::Volvo() {
	this->capacity = 80.0;
	this->consum = 9.5;
	this->spdRain = 190;
	this->spdSun = 200;
	this->spdSnow = 150;
}
double Volvo::GetCapacity() {
	return this->capacity;
}
double Volvo::GetConsum() {
	return this->consum;
}
int Volvo::GetspdRain() {
	return this->spdRain;
}
int Volvo::GetspdSun() {
	return this->spdSun;
}
int Volvo::GetspdSnow() {
	return this->spdSnow;
}