#include "clasa2.h"
#include <iostream>
void MovieSeries::init() {
	count = 0;
}
void MovieSeries::add(Movie* m) {
	movies[count++] = m;
}
void MovieSeries :: print() {
	for (int i = 0; i < count; i++)
		std::cout << movies[i]->addname() << "\n" << "Lansare: " << movies[i]->addyear() 
		<< "\n" << "scor imdb: " << movies[i]->addscore() << "\n" << "Lungime: " << movies[i]->addlength() << "\n" << "Ani trecuti: " << movies[i]->yrspassed()<<"\n";
}
void MovieSeries::sort() {
	for (int i = 1; i < count; i++) {
		Movie *key = movies[i];
		int j = i - 1;
		while (j >= 0 && movies[j]->yrspassed() > key->yrspassed()) {
			movies[j + 1] = movies[j]; j--;
		}
		movies[j+1] = key;
	}
}