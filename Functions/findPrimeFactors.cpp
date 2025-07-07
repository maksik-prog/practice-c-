#include "findPrimeFactors.h"
#include "cmath"
#include <sstream>

bool* findPrimeFactors::eratosthenes(int n)
{
    bool* primeNumbers = new bool[n + 1];
    for (int i = 0; i <= n; i++) {
        primeNumbers[i] = true;
    }
    primeNumbers[0] = false;
    primeNumbers[1] = false;

    int i = 2;

    while (i * i <= n) 
    {
        if (primeNumbers[i])
        {
            int j = i * i; 
            while (j <= n)
            {
                primeNumbers[j] = false;
                j += i; 
            }
        }
        i++;
    }

    return primeNumbers;
}

std::string findPrimeFactors::canonicForm(int n, bool* primeNumbers)
{
   
    if (primeNumbers[n]) return std::to_string(n);

    std::ostringstream oss;
    bool first = true;
    int temp_n = n; 

    for (int i = 2; i <= temp_n; i++)
    {
        if (primeNumbers[i])
        {
            int count = 0;
            while (temp_n % i == 0)
            {
                count++;
                temp_n /= i;  
            }

            if (count > 0)
            {
                if (!first) oss << "*";

                if (count == 1)
                    oss << i;
                else
                    oss << i << "^" << count;

                first = false;
            }
        }
    }

    return oss.str();
}
