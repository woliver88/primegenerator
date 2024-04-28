#include "willan.h"

extern long long unsigned int * cache;
extern long long unsigned int * outer_cache;

int willan(int number)
{
    // Takes 'number', the 'n'th prime number required
    // Returns the 'n'th prime number
    int total = 0;
    for (int i = 1; i <= (pow(2, number)); i++)
    {
        int to_add = willan_inter(number, i);
        // printf("to_add: %i\n", to_add);
        total = total + to_add;
    }
    return total + 1;
}

int wilsons_inter(long long unsigned int number)
{
    // The lower half of the fraction with in the full equation
    // This sums from testprime(j) to testprime(i)

    if ((number < STD_CACHE_LIMIT) && (outer_cache[number] != 0)) {
        return outer_cache[number];
    }
    else {
        int total = 0;
        for (long long unsigned int j = 1; j <= number; j++)
        {
            int tp = testprime(j, cache);
            total = total + tp;
        }
        if (number < STD_CACHE_LIMIT) {
            outer_cache[number] = total;
        }
        return total;
    }
}

int willan_inter(int number, long long unsigned int iter)
{
    // Component in equation within uter floor function
    long double inter_value = (long double)number / (long double)wilsons_inter(iter);

    long double inter_value_2 = pow(inter_value, ((long double)1 / number));
    return (int)inter_value_2;
}