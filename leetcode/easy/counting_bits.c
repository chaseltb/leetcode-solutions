#include <stdlib.h>

int countOnes(int num) {
    int count = 0;

    while (num > 0) {
        if (num % 2 == 1) {
            count++;
        }
        num = num / 2;
    }

    return count;
}

int* countBits(int n, int* returnSize) {
    *returnSize = n + 1;

    int *ans = (int *)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        ans[i] = countOnes(i);
    }

    return ans;
}
