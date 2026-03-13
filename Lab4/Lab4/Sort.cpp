#include "Sort.h"
#include <ctime>
#include <cstdarg>
#include <iostream>
#include <algorithm>
Sort::Sort(int min, int max, int cnt) {
	this->cnt = cnt;
	this->elem = new int[cnt];
	for (int i = 0; i < cnt; i++)
		this->elem[i] = min + rand() % (max - min + 1);
}
Sort::Sort(std::initializer_list<int> list) {
	this->cnt = list.size();
	this->elem = new int[cnt];
	const int* point = list.begin();
	for (int i = 0; i < cnt; i++)
		this->elem[i] = point[i];

}
Sort::Sort(int* vector, int cnt) {
	this->cnt = cnt;
	this->elem = new int[cnt];
	for (int i = 0; i < cnt; i++)
		this->elem[i] = vector[i];
}
Sort::Sort(int cnt, ...) {
	this->cnt = cnt;
	this->elem = new int[cnt];
	va_list args;
	va_start(args, cnt);
	for (int i = 0; i < cnt; i++)
		this->elem[i] = va_arg(args, int);
	va_end(args);
}
Sort::Sort(const char* str) {
	this->cnt = 1;
	int idx = 0,nr=0;
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == ',')this->cnt++;
	this->elem = new int[cnt];
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ',') {
			this->elem[idx++] = nr;
			nr = 0;
		}
		else
			nr = nr * 10 + str[i] - '0';
		this->elem[idx] = nr;
	}

}
void Sort::InsertSort(bool ascendent) {
	for (int i = 1; i < cnt; i++) {
		int key = elem[i];
		int j = i - 1;

		while (j >= 0) {
			bool condition = ascendent ? (elem[j] > key) : (elem[j] > key);
			if (condition) {
				elem[j + 1] = elem[j];
				j--;
			}
			else {
				break;
			}
		}
		elem[j + 1] = key;
	}
}
void Sort::BubbleSort(bool ascendent) {
	bool swapped;
	for (int i = 0; i < cnt; i++) {
		swapped = false;
		for (int j = 0; j < cnt - i - 1; j++) {
			if (elem[j] > elem[j + 1]) {
				std::swap(elem[j], elem[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}
void Sort::QuickSort(bool ascendent) {
	Quickrecursie(0, cnt - 1, ascendent);
}
void Sort::Quickrecursie(int mic, int mare, bool ascendent) {
	if (mic < mare) {
		int pi = Partition(mic, mare, ascendent);
		Quickrecursie(mic, pi - 1, ascendent);
		Quickrecursie(pi + 1,mare, ascendent);
	}
}
int Sort::Partition(int mic, int mare, bool ascendent) {
	int pivot = elem[mare];
	int i = (mic - 1);

	for (int j = mic; j <= mare - 1; j++) {
		bool condition = ascendent ? (elem[j] < pivot) : (elem[j] > pivot);
		if (condition) {
			i++;
			int temp = elem[i];
			elem[i] = elem[j];
			elem[j] = temp;
		}
	}
	int temp = elem[i + 1];
	elem[i + 1] = elem[mare];
	elem[mare] = temp;

	return (i + 1);
}
void Sort::Print() {
	for (int i = 0; i < cnt; i++)
		std::cout << elem[i]<<" ";
	std::cout << "\n";
}
int Sort::GetElementsCount() {
	return cnt;
}
int Sort::GetElementFromIndex(int index) {
	if (index >= 0 && index < cnt) {
		return elem[index];
	}
	return -1;
}