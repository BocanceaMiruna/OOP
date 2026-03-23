#include <iostream>
#include <string.h>
#include "Number.h"
Number::Number(const char* val, int b){
	if (val != nullptr) {
		int len = (int)strlen(val);
		this->value = new char[len + 1];
		strcpy_s(this->value, len + 1, val);
	}
	else
		this->value = nullptr;
	this->base = b;
}
Number::~Number() {
	if (this->value != nullptr) {
		delete[] this->value;
		this->value = nullptr;
	}
}
int Number::GetBase()const {
	return this->base;
}
Number::Number(const Number& to_copy)noexcept {
	int len = (int)strlen(to_copy.value)+1;
	this->value = new char[len];
	this->base =to_copy.base;
	strcpy_s(this->value,len, to_copy.value);
}
Number::Number(Number&& to_move)noexcept{
	this->value = to_move.value;
	this->base = to_move.base;
	to_move.value = nullptr;
	to_move.base = 0;
}
int Number::baza10()const {
	int val = 0;
	int len =(int) strlen(this->value);
	for (int i = 0; i < len; i++) {
		int cifra;
		if (this->value[i] >= '0' && this->value[i] <= '9')
			cifra = this->value[i] - '0';
		else
			cifra = this->value[i] - 'A' + 10;

		val = val * this->base + cifra;
	}
	return val;
}
void Number::SwitchBase(int newBase) {
	if (this->base == newBase) return;
	char val[100];
	int nr = this->baza10();
	char len = 0;
	while (nr) {
		int rest = nr % newBase;
		if(rest>=10)
		val[len++] = (char)(rest + 'A' - 10);
	else
		val[len++] = (char)(rest + '0');
		nr /= newBase;
	}
	val[len] = '\0';
	delete[]this->value;
	this->value = new char[len+1];
	for (int i = 0; i < len; i++) {
		this->value[i] = val[len - i - 1];
	}
	this->value[len] = '\0';
	this->base = newBase;
}
char Number::operator[](int idx) const {
	if (this->value != nullptr && idx >= 0 && idx < (int)strlen(this->value))
		return this->value[idx];
	return '\0';
}
Number operator+(const Number&x,const Number&y) {
	int v1 = x.baza10();
	int v2 = y.baza10();
	int s = v1 + v2;
	int maxbase = 0;
	if (x.GetBase() > y.GetBase())
		maxbase = x.GetBase();
	else
		maxbase = y.GetBase();
	char buff[256];
	int cs = s,i=0;
	while (cs) {
		buff[i++] = (cs % 10) + '0';
		cs /= 10;
	}
	buff[i] = '\0';
	for (int j = 0; j < i / 2; j++) {
		char aux = buff[j];
		buff[j] = buff[i - j - 1];
		buff[i - j - 1] = aux;
	}
	Number rez(buff, 10);
	rez.SwitchBase(maxbase);
	return rez;
}
Number operator-(const Number &x,const  Number&y) {
	int v1 = x.baza10();
	int v2 = y.baza10();
	int d = v1 - v2;
	int maxbase = 0;
	if (x.GetBase() > y.GetBase())
		maxbase = x.GetBase();
	else
		maxbase = y.GetBase();
	char buff[256];
	bool neg = false;
	if (d < 0) {
		neg = true;
		d = -d;
	}
	int cd = d, i = 0;
	while (cd) {
		buff[i++] = (cd % 10) + '0';
		cd /= 10;
	}
	if (neg == true)
		buff[i++] = '-';
	buff[i] = '\0';
	for (int j = 0; j < i / 2; j++) {
		char aux = buff[j];
		buff[j] = buff[i - j - 1];
		buff[i - j - 1] = aux;
	}
	Number rez(buff, 10);
	rez.SwitchBase(maxbase);
	return rez;
}
bool Number::operator>(const Number& x)const {
	Number tempThis(*this);
	Number tempX(x);
	return tempThis.baza10() > tempX.baza10();
}
bool Number::operator<(const Number& x)const {
	Number tempThis(*this);
	Number tempX(x);
	return tempThis.baza10() < tempX.baza10();
}
bool Number::operator>=(const Number& x)const {
	Number tempThis(*this);
	Number tempX(x);
	return tempThis.baza10() >= tempX.baza10();
}
bool Number::operator<=(const Number& x)const {
	Number tempThis(*this);
	Number tempX(x);
	return tempThis.baza10() <= tempX.baza10();
}
bool Number::operator==(const Number& x)const {
	Number tempThis(*this);
	Number tempX(x);
	return tempThis.baza10() == tempX.baza10();
}
Number& Number::operator--() {
	if (value != nullptr && strlen(value) > 0) {
		int len =(int) strlen(value);
		for (int i = 0; i < len; i++)
			value[i] = value[i + 1];
	}
	return *this;
}
Number Number::operator--(int) {
	Number x(*this);
	if (value != nullptr && strlen(value) > 0) {
		int len =(int) strlen(value);
		value[len - 1] = '\0';
	}
	return x;
}
int Number::GetDigitsCount()const {
	if (this->value == nullptr) return 0;
	return (int)strlen(this->value);
}
Number::Number(int val) {
	this->base = 10;
	char buff[256];
	int i = 0;
	bool esteNegativ = false;
	if (val == 0) {
		buff[i++] = '0';
	}
	else {
		if (val < 0) {
			esteNegativ = true;
			val = -val;
		}
		while (val > 0) {
			buff[i++] = (val % 10) + '0';
			val /= 10;
		}
		if (esteNegativ)
			buff[i++] = '-';
	}
	buff[i] = '\0';
	int lungime = i;
	this->value = new char[lungime + 1];
	for (int j = 0; j < lungime; j++)
		this->value[j] = buff[lungime - j - 1];
	this->value[lungime] = '\0';
}

Number& Number::operator=(const Number& other) {
	if (this != &other) { 
		delete[] this->value;
		this->base = other.base;
		int len = (int)strlen(other.value);
		this->value = new char[len + 1];
		strcpy_s(this->value, len + 1, other.value);
	}
	return *this;
}

Number& Number::operator=(Number&& other) noexcept {
	if (this != &other) {
		delete[] this->value;
		this->value = other.value;
		this->base = other.base;
		other.value = nullptr;
		other.base = 0;
	}
	return *this;
}
Number& Number::operator+=(const Number& other) {
	int suma = this->baza10() + other.baza10();
	int nouaBaza = (this->base > other.base) ? this->base : other.base;
	char buff[256];
	int i = 0;
	if (suma == 0) buff[i++] = '0';
	else
		while (suma > 0) {
			buff[i++] = (suma % 10) + '0';
			suma /= 10;
		}
	buff[i] = '\0';
	for (int j = 0; j < i / 2; j++) {
		char aux = buff[j];
		buff[j] = buff[i - j - 1];
		buff[i - j - 1] = aux;
	}
	delete[] this->value;
	this->value = new char[i + 1];
	strcpy_s(this->value, i + 1, buff);
	this->base = 10;
	this->SwitchBase(nouaBaza);
	return *this;
}
Number& Number::operator=(const char* val) {
	if (this->value != nullptr) delete[] this->value;
	int len = (int)strlen(val);
	this->value = new char[len + 1];
	strcpy_s(this->value, len + 1, val);
	return *this;
}
void Number::Print() {
	std::cout << this->value << " "<< this->base<<'\n';
}