#pragma once
class Number
{
	char* value;
	int base;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(const Number& to_copy)noexcept;
	Number(Number&&to_move)noexcept;
	bool operator<(const Number &x)const;
	bool operator>(const Number &x)const;
	bool operator>=(const Number &x)const;
	bool operator<=(const Number &x)const;
	bool operator==(const Number &x)const;
	char operator[](int idx)const;
	int baza10() const ;
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount()const; // returns the number of digits for the current number
	int  GetBase()const; // returns the current base
	friend Number operator+(const Number& x,const Number& y);
	friend Number operator-(const Number& x,const Number& y);
	Number operator--(int);//ult cif
	Number&operator--();//prima cif
	Number(int val);
	Number& operator=(const Number& other);
	Number& operator=(Number&& other) noexcept;
	Number&operator=(const char* val);
	Number& operator+=(const Number& other);
};
