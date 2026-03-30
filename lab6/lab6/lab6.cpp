#include <iostream>
#include "Circuit.h"
#include "BMW.h"
#include "Volvo.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
int main() {
    Circuit c;
    c.setLength(1000);
    c.setWeather(Weather::Rain);
    car* masina1 = new BMW();
    masina1->SetDriver(new Driver("Max", 1.5));
    masina1->SetTires(TypeTires::Wet);
    c.AddCar(masina1);
    car* masina2 = new Fiat();
    masina2->SetDriver(new Driver("Incepator", 0.1));
    masina2->SetTires(TypeTires::Snow);
    c.AddCar(masina2);
    car* masina3 = new Volvo();
    masina3->SetDriver(new Driver("Lewis", 1.4));
    masina3->SetTires(TypeTires::Slicks);
    c.AddCar(masina3); 
    c.Race();
    c.ShowFinalRanks();
    c.DNF();
    return 0;
}