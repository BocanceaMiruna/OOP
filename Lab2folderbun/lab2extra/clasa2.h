#pragma once
#include "Movies.h"
class MovieSeries {
	int count;
	Movie* movies[16];
public:
	void init();
	void add(Movie* m);
	void print();
	void sort();
};