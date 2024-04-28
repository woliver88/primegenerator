#include "test_file.h"

// redefine assert to set a boolean flag
// this assert statement is continually updated while proceeding through tests
#ifdef assert
#undef assert
#endif
#define assert(x) (rslt = rslt && (x))

static int rslt = 1;
static int num_tests;

bool test_testprime(long long unsigned int prime_to_test, int isprime)
// return 1 if correct
{
    printf("Number: %llu\n", prime_to_test);

    if (testprime(prime_to_test) == isprime)
    {
        return true;
    }
    return false;
}

static int numberstructlistlen = 12;

// This is a pointer to an array length 12
static struct number numberstructlist[] = {
    {1, true},
    {7, true},
    {11, true},
    {101, true},
    {787, true},
    {1009, true},
    {10000019, true},
    {4, false},
    {98, false},
    {539, false},
    {5757, false},
    {5758, false},
    {10000021, false}};

// This is juts a pointer to an array (i.e. the first element)
int test_testprimes(struct number numberstructpointer[], int numberstructlistlen)
{
    int tests_passed = 0;
    for (int i = 0; i < numberstructlistlen; i++)
    {
        long long unsigned int num = numberstructpointer[i].num;
        int prime = (int)numberstructpointer[i].prime;

        bool res = test_testprime(num, prime);
        if (res)
        {
            tests_passed++;
        }
    }

    assert(tests_passed == numberstructlistlen);
    printf("Number of tests passed: %i of %i\n", tests_passed, numberstructlistlen);
    return 0;
}


static int primelesslistlen = 5;
static struct primesless primelesslist[] = {
    {5, 4},
    {10, 5},
    {200, 47},
    {500, 96},
    {1000, 169},
};

int test_wilsons_inter(struct primesless primelesslist[], int primelesslistlen)
{
    int tests_passed = 0;
    for (int i = 0; i < primelesslistlen; i++)
    {
        int num = primelesslist[i].num;
        int primes_less_than_num = (int)primelesslist[i].primes_less_than_num;

        int res = wilsons_inter(num);
        printf("For value: %i, number is: %i, expected: %i\n", num, res, primes_less_than_num);
        if (res == primes_less_than_num)
        {
            tests_passed++;
        }
    }

    assert(tests_passed == primelesslistlen);
    printf("Number of tests passed: %i of %i\n", tests_passed, primelesslistlen);
    return 0;
}

int test_modular_factorial_recur()
{
    long long unsigned int *cache = create_cache(RECUR_CACHE_LIMIT);
    for (int i = 1; i <= 21; i++)
    {
        long long unsigned recurval = modular_factorial_recur(i, cache);
        printf("recur value for i = %i is: %llu\n", i, recurval);
    }
    free(cache);
    return 0;
}

int main()
{
    test_testprimes(numberstructlist, numberstructlistlen);
    test_wilsons_inter(primelesslist, primelesslistlen);
    printf("All tests passed: %s\n", rslt ? "true" : "false");
    // test_modular_factorial_recur();
    return 0;
}