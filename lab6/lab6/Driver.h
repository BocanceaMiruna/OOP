#pragma once
#include <cstring>
class Driver {
	char name[50];
	double skill;
public:
    Driver(const char* n, double s) {
        strcpy_s(this->name, sizeof(this->name), n);
        this->skill = s;
    }
    const char* GetName() { return this->name; }
    double GetSkill() { return this->skill; }
};