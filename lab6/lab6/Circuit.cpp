#include <iostream>
#include "Circuit.h"
void Circuit::setLength(int len) { this->length = len; }
void Circuit::setWeather(Weather w) { this->weather = w; }
Circuit::Circuit() {
	this->carcnt = 0;
	this->length = 0;
	this->weather = Weather::Sun;

}
Circuit::~Circuit() {
	for (int i = 0; i < this->carcnt; i++) {
		delete this->cars[i];
	}
}
void Circuit::AddCar(car *c) {
	if (this->carcnt <= 25) {
		this->cars[this->carcnt] = c;
		this->carcnt++;
	}
}
void Circuit::Race() {
	for (int i = 0; i < this->carcnt; i++) {
		car* currcar = this->cars[i];
		int spd = 0;
		if (this->weather == Weather::Sun) spd = currcar->GetspdSun();
		if (this->weather == Weather::Rain) spd =currcar-> GetspdRain();
		if (this->weather == Weather::Snow) spd = currcar->GetspdSnow();
		double spdvreme = 1;//pt a nu schimba vitezele masina pierde viteza daca nu are rotile corespunzatoare
		TypeTires t = currcar->GetTires();
		if (this->weather == Weather::Sun && t==TypeTires::Slicks) spdvreme=1;
		if (this->weather == Weather::Sun && t == TypeTires::Wet) spdvreme = 0.8;
		if (this->weather == Weather::Sun && t == TypeTires::Snow) spdvreme = 0.5;
		if (this->weather == Weather::Rain && t == TypeTires::Wet) spdvreme =1;
		if (this->weather == Weather::Rain && t == TypeTires::Slicks) spdvreme = 0.3;
		if (this->weather == Weather::Rain && t == TypeTires::Snow) spdvreme = 0.9;
		double realspd = 0;
			realspd =spd * spdvreme;
		double needcap = (this->length / 100.00)*currcar->GetConsum();
		this->res[i].drv = currcar;
		if (currcar->GetCapacity() >= needcap) {
			this->res[i].finish = true;
			this->res[i].time = this->length / (realspd * currcar->GetDriver()->GetSkill());
		}
		else {
			this->res[i].finish = false;
			this->res[i].time = 999999.0;
		}

	}
}
void Circuit::ShowFinalRanks() {
	for (int i = 0; i < this->carcnt - 1; i++) {
		for (int j = 0; j < this->carcnt - i - 1; j++) {
			if (this->res[j].time > this->res[j + 1].time) {
				Results temp = this->res[j];
				this->res[j] = this->res[j + 1];
				this->res[j + 1] = temp;
			}
		}
	}
	int rank = 1;
	for (int i = 0; i < this->carcnt; i++) {
		if (this->res[i].finish == true) {
			std::cout << rank << ". "<< this->res[i].drv->GetDriver()->GetName()<< " " << this->res[i].time << "\n";
			rank++;
		}
	}
}
void Circuit::DNF() {
	std::cout << "DNF:\n";
	bool ok = true;
	for (int i = 0; i < this->carcnt; i++)
		if (this->res[i].finish == false) {
			std::cout << this->res[i].drv->GetDriver()->GetName() << "\n";
			ok = false;
		}
		if (ok)
			std::cout << "Toti au terminat cursa\n";
}