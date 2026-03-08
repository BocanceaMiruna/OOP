#include "Students.h"
#include <cstring>
int cmpnume(students& s1, students & s2) {
	int x = (strcmp(s1.getnume(), s2.getnume()));
		if (x == 0)return 0;
		if (x == 1)return 1;
		return -1;
}
int cmpmate(students& s1, students& s2) {
	if (s1.getmate() == s2.getmate())return 0;
	if (s1.getmate() > s2.getmate())return 1;
	return -1;
}
int cmpeng(students& s1, students& s2) {
	if (s1.geteng() == s2.geteng())return 0;
	if (s1.geteng() > s2.geteng())return 1;
	return -1;
}
int cmphistory(students& s1, students& s2) {
	if (s1.gethistory() == s2.gethistory())return 0;
	if (s1.gethistory() > s2.gethistory())return 1;
	return -1;
}
int cmpaverage(students& s1, students& s2) {
	if (s1.average() == s2.average())return 0;
	if (s1.average() > s2.average())return 1;
	return -1;
}