#include <stdlib.h>

#define OFFSET 10000
#define RANGE 20001

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int *freq = (int *)calloc(RANGE, sizeof(int));

    // Count frequencies
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + OFFSET]++;
    }

    // Buckets indexed by frequency
    Node **bucket = (Node **)calloc(numsSize + 1, sizeof(Node *));

    for (int i = 0; i < RANGE; i++) {
        if (freq[i] > 0) {
            Node *node = (Node *)malloc(sizeof(Node));
            node->value = i - OFFSET;
            node->next = bucket[freq[i]];
            bucket[freq[i]] = node;
        }
    }

    int *ans = (int *)malloc(sizeof(int) * k);
    int idx = 0;

    // Collect from highest frequency to lowest
    for (int f = numsSize; f >= 1 && idx < k; f--) {
        Node *cur = bucket[f];

        while (cur != NULL && idx < k) {
            ans[idx++] = cur->value;
            cur = cur->next;
        }
    }

    *returnSize = k;

    // Free memory
    for (int i = 1; i <= numsSize; i++) {
        Node *cur = bucket[i];
        while (cur) {
            Node *next = cur->next;
            free(cur);
            cur = next;
        }
    }

    free(bucket);
    free(freq);

    return ans;
}
