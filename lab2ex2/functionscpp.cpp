
#include "Students.h"
#include <cstring>
void students::nume(const char *n) {
	strcpy_s(this->student, n);
	
}
char* students::getnume() {
	return student;
}
void students::addmate(float x) {
	if (x >= 1.0 && x <= 10.0)
		this->mate = x;
}
float students::getmate() {
	return mate;
}
void students::addeng(float x) {
	if (x >= 1.0 && x <= 10.0)
		this->eng = x;
}
float students::geteng() {
	return eng;
}
void students::addhistory(float x) {
	if (x >= 1.0 && x <= 10.0)
		this->history = x;
}
float students::gethistory() {
	return history;
}
float students::average() {
	return (this->mate + this->eng + this->history) / 3.0f;
}