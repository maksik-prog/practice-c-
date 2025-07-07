#pragma once
#include<string>

class findPrimeFactors
{
public:
	bool* eratosthenes(int n);

	std::string canonicForm(int n, bool* primeNumbers);
};

