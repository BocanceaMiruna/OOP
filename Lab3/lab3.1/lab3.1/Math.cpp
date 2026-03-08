#include "Math.h"
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
int Math::Add(int x , int y ) {
	return x + y;
}
int Math::Add(int x, int y, int z) {
	return x + y + z;
}
int Math::Add(double x,double y) {
	return (int) x + (int)y;
}
int Math::Add(double x, double y,double z) {
	return (int)x + (int)y+(int)z;
}
int Math::Mul(int x, int y) {
	return x * y;
}
int Math::Mul(int x, int y,int z) {
	return x * y*z;
}
int Math::Mul(double x, double y) {
	return (int)x * (int)y;
}
int Math::Mul(double x, double y,double z) {
	return (int)x *(int) y*(int)z;
}
int Math::Add(int count, ...) {
	va_list args;
	va_start(args, count);
	int suma=0;
	for (int i = 0; i < count; i++)
		suma += va_arg(args, int);
	va_end(args);
	return suma;
}
 char* Math::Add(const char* x, const char* y) {
    if (x == nullptr || y == nullptr) {
        return nullptr;
    }
    size_t lx = strlen(x);
    size_t ly = strlen(y);
    size_t totalSize = lx + ly + 1;
    char* fin = (char*)malloc(totalSize);
    if (fin == nullptr) {
        return nullptr;
    }
    strcpy_s(fin, totalSize, x);
    strcat_s(fin, totalSize, y);

    return fin;
}