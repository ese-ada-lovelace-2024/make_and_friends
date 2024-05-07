#include "primes.h"

#include <vector>

/* Function returns a vector (of long integers)
   containing the first n prime numbers. 
*/

std::vector<long> primes(int n)
{
    std::vector<long> result;
    if (n <= 0)
        return result;
    result.resize(n);
    result[0]=2;
    if (n == 1)
        {
        return result;
        }

    int count = 1;
    
    for (long test =3; count<n; test+=2)
    {   
        bool is_prime = true;
        for (long j = 0; j<count && result[j]*result[j] <= test; j++)
        {
            if (test % result[j] == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            result[count++] = test;
        }
    }
    return result;
}

/* Function checks if a number is prime. 
   The function returns true if the number is prime, 
   and false otherwise. 

   The optional argument construct is the number of
   small primes to find before running the checks.
*/

bool is_prime(long n, int construct)
{   
    if (n<2)
        return false;
    else if (n<4)
        return true;

    std::vector<long> small_primes = primes(construct);

    for (long i = 0; i<construct; i++)
    {
        if (n % small_primes[i] == 0)
            return false;
        if (small_primes[i]*small_primes[i] > n)
            return true;
    }

    long test;
    if (construct >1) {
        test = small_primes[construct-1] + 2;
    } else {
        if (n % 2 == 0)
            return false;
        test = 3;
    }

    while (true)
    {
        if (n % test == 0)
            return false;
        
        if (test*test > n)
            return true;

        test += 2;
    }

    return true;
}