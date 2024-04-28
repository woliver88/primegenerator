#include <stdbool.h>
#include "../wilsons.h"
#include "../willan.h"
#include "../utils.h"

struct number
{
    long long unsigned int num;
    bool prime;
};


// This takes a number, and the number of primes less that in
struct primesless
{
    long long unsigned int num;
    int primes_less_than_num;
};

bool test_testprime(long long unsigned int prime_to_test, int isprime);
int test_testprimes(struct number numberstructpointer[], int numberstructlistlen);
int test_wilsons_inter(struct primesless primelesslist[], int primelesslistlen);
int test_modular_factorial_recur();