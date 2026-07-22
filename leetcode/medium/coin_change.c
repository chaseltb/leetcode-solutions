#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int coinChange(int* coins, int coinsSize, int amount) {
    int *dp = (int *)malloc((amount + 1) * sizeof(int));

    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    int answer;

    if (dp[amount] > amount) {
        answer = -1;
    }
    else {
        answer = dp[amount];
    }

    free(dp);

    return answer;
}
