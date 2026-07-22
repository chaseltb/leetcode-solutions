#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);

    if (numRows == 1 || numRows >= len) {
        char *ans = (char *)malloc(len + 1);
        strcpy(ans, s);
        return ans;
    }

    char *ans = (char *)malloc(len + 1);
    int idx = 0;
    int cycle = 2 * numRows - 2;

    for (int row = 0; row < numRows; row++) {
        for (int j = row; j < len; j += cycle) {
            ans[idx++] = s[j];

            int diag = j + cycle - 2 * row;

            if (row != 0 && row != numRows - 1 && diag < len)
                ans[idx++] = s[diag];
        }
    }

    ans[idx] = '\0';
    return ans;
}
