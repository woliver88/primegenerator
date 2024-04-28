#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testprime(long long unsigned int  number, long long unsigned int *cache);
long long unsigned int factorial(int number);
long long unsigned int modular_factorial(long long unsigned int number);
long long unsigned int modular_factorial_recur(int number, long long unsigned int * cache);
long long unsigned int * create_cache(int cache_length);