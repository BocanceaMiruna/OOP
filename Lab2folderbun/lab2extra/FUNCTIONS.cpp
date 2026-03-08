#include "Movies.h"
#include <cstring>
void Movie::set_name(const char*  x) {
	strcpy_s(this->name,x);
}
char* Movie::addname() {
	return name;
}
void Movie::set_year(int x) {
	this->year = x;
}
int Movie::addyear() {
	return this->year;
}
void Movie::set_length(int x) {
	this->length = x;
}
int Movie::addlength() {
	return this->length;
}
void Movie::set_score(float x) {
	this->score =x;
}
float Movie::addscore() {
	return this->score;
}
int Movie::yrspassed() {
	return 2026 - year;
}