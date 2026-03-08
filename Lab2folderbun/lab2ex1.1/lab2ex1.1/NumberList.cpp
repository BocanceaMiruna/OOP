#include "Header.h"//NumberList.cpp
#include <iostream>
void NumberList::Init() {
	this->count = 0;
}
bool NumberList::Add(int x) {
	numbers[count++] = x;
	if (count > 10)
		return false;
	return true;
}
void NumberList::Sort() {
	for (int i = 1; i <count; i++) {
		int key = numbers[i];
		int j = i - 1;
		while (j >= 0 && numbers[j] > key) {
			numbers[j + 1] = numbers[j];
			j--;
		}
		numbers[j + 1] = key;
	}
}
void NumberList::Print() {
	for (int i = 0; i <count; i++)
		std::cout << numbers[i]<<" ";
}