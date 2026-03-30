#include "Fiat.h"
Fiat::Fiat() {
	this->capacity = 20.0;
	this->consum = 10.5;
	this->spdRain = 190;
	this->spdSun = 220;
	this->spdSnow = 100;
}
double Fiat::GetCapacity() {
	return this->capacity;
}
double Fiat::GetConsum() {
	return this->consum;
}
int Fiat::GetspdRain() {
	return this->spdRain;
}
int Fiat::GetspdSun() {
	return this->spdSun;
}
int Fiat::GetspdSnow() {
	return this->spdSnow;
}