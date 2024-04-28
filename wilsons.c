#include "wilsons.h"
#include "utils.h"

int testprime(long long unsigned int number, long long unsigned int *cache)
{
    // returns 1 if prime, 0 if composite
  
    if ((number < STD_CACHE_LIMIT) && (cache[number] != 0)) {
        return cache[number];
    }
    else {
        long long unsigned int factorial_value = modular_factorial(number - 1);
        // printf("factorial: %d\n", factorial_value);
        
        factorial_value = (factorial_value + 1) % number;
        // the output here will be 0 if prime

        
        // Using modular arithmetic negates the requirements for these steps
        // printf("factorial: %llu\n", factorial_value);
        // long double inter_value = M_PI * factorial_value;

        // printf("inter_value: %Lf\n", inter_value);
        // long double inter_value_2 = inter_value / number;

        // printf("inter_value_2: %Lf\n", inter_value_2);
        // long double inter_value_3 = cos(inter_value_2);
        
        long double inter_value_3 = cos(factorial_value);

        // casting as int acts as floor function
        // squaring output of cosine function
        int final_value = (int)(inter_value_3 * inter_value_3);
        if (number < STD_CACHE_LIMIT) {
            cache[number] = final_value;
        }

        return final_value;
    
    }
}

long long unsigned int modular_factorial(long long unsigned int number)
{
    // Based on Wilson's Theorem
    
    // This takes and integer 'number' and calculates the
    // factorial of 'number' mod 'number + 1'
    // 'number + 1' is the prime being tested (confusing arguments passed in)
    
    // Output x : (0,1,2,..., p) where p is value of 'number'
    // and equivocal to -1 indicating a prime number

    long long unsigned int mod_num = number + 1;
    long long unsigned int factorial_value = 1;
    for (int i = 1; i <= number; i++)
    {
        factorial_value = factorial_value % mod_num;
        factorial_value = factorial_value * i;
    }
    return factorial_value % mod_num;
}

long long unsigned int factorial(int number)
{
    long long unsigned int factorial_value = 1;
    for (int i = 1; i <= number; i++)
    {
        factorial_value = factorial_value * i;
    }
    return factorial_value;
}

// POC for caching - Not used in final function
long long unsigned int modular_factorial_recur(int number, long long unsigned int * cache)
{
    if ((number != 1) && (number < RECUR_CACHE_LIMIT))
    {
        if (cache[number] != 0) {
            return cache[number];
        }
        else {
            long long unsigned int temp;
            temp = modular_factorial_recur(number - 1, cache);
            long long unsigned int mult_temp = number * temp;
            cache[number] = mult_temp;
            return mult_temp;
        }
    }
    else
    {
        return 1;
    }
}
