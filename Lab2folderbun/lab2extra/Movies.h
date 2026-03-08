#pragma once
class Movie {
	char name[256];
	int year;
	float score;
	int length;
public:
	void set_name(const char* name);
	char *addname();
	void set_year(int x);
	int addyear();
	void set_length(int x);
	int addlength();
	void set_score(float x);
	float addscore();
	int yrspassed();
	friend class MovieSeries;
};