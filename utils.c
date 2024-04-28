#include "utils.h"

long long unsigned int * create_cache(int cache_length) {
    long long unsigned int * cache = (long long unsigned int *)malloc(cache_length*sizeof(long long unsigned int));
    for (int i = 0; i < cache_length; i ++) {
        cache[i] = 0;
    }
    return cache;
}