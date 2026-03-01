#pragma once
class students {
	char student[20];
	float mate;
	float eng;
	float history;
public:
	void nume(const char* n);
	char *getnume();
	void addmate(float x);
	float getmate();
	void addeng(float x);
	float geteng();
	void addhistory(float x);
	float gethistory();
	float average();
};