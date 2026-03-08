
#include <iostream>
#include "Math.h"
int main()
{
	std::cout << Math::Add(2, 3) << "\n";
	std::cout << Math::Add(2, 3, 6) << "\n";
	std::cout << Math::Add(2.2, 3.3) << "\n";
	std::cout << Math::Add(2.1, 3.1, 4.2) << "\n";
	std::cout << Math::Mul(2, 3) << "\n";
	std::cout << Math::Mul(2, 3, 2) << "\n";
	std::cout << Math::Mul(2.2, 3.3) << "\n";
	std::cout << Math::Add("ana", "mere") << "\n";
	std::cout << Math::Add(5,2,2) << "\n";
}

