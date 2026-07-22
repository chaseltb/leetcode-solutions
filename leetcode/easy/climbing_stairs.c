#include <stdio.h>
#include <stdlib.h>

int climbStairs(int n) {
    if (n < 2) {
        return n;
    }

    // Store the number of ways in array
    int* cache = (int*)malloc(n * sizeof(int));
    
    cache[0] = 1;
    cache[1] = 2;

    // Fill up cache using dynamic programming
    for (int i = 2; i < n; i++) {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    int result = cache[n - 1];
    free(cache);

    return result;
}
