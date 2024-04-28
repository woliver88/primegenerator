#include <stdbool.h>
#include "wilsons.h"
#include "willan.h"
#include "utils.h"

long long unsigned int * cache;
long long unsigned int * outer_cache;

int main(void)
{
    int i;

    cache = create_cache(STD_CACHE_LIMIT);
    outer_cache = create_cache(STD_CACHE_LIMIT);
    while (true)
    {
        // #ifdef CACHE
        // printf("TEST CACHE");
        // #endif
        printf("Enter 'n' to get the 'nth' prime:\n");
        scanf("%d", &i);
        if (i == 0)
        {
            return 0;
        }
        int prime = willan(i);
        printf("The %i'th prime is: %i\n", i, prime);
        
    }
    // Never reached but serve as memory aid
    free(cache);
    free(outer_cache);
    
    return 0;
}
