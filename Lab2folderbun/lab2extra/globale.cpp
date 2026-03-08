#include "Movies.h"
#include <cstring>
int movie_compare_name(Movie& m1, Movie& m2) {
	int x = strcmp(m1.addname(), m2.addname());
		if (x == 0)return 0;
	if (x == 1)return 1;
	return -1;
}
int movie_compare_year(Movie& m1, Movie& m2) {
	if (m1.addyear() == m2.addyear())return 0;
	if (m1.addyear() > m2.addyear())return 1;
	return -1;
}
int movie_compare_length(Movie& m1, Movie& m2) {
	if (m1.addlength() == m2.addlength())return 0;
	if (m1.addlength() > m2.addlength())return 1;
	return -1;
}
int movie_compare_score(Movie& m1, Movie& m2) {
	if (m1.addscore() == m2.addscore())return 0;
	if (m1.addscore() > m2.addscore())return 1;
	return -1;
}
int movie_compare_passed_years(Movie& m1, Movie& m2) {
	if (m1.yrspassed() == m2.yrspassed())return 0;
	if (m1.yrspassed() > m2.yrspassed())return 1;
	return -1;
}