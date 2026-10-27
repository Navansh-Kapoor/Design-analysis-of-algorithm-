
#include <stdio.h>
#include <string.h>

int main() {
    char X[100], Y[100];
    int dp[100][100];
    int m, n, i, j, index;

    printf("Enter first string: ");
    scanf("%99s", X);

    printf("Enter second string: ");
    scanf("%99s", Y);

    m = strlen(X);
    n = strlen(Y);

    // Initialize first row and column
    for (i = 0; i <= m; i++)
        dp[i][0] = 0;

    for (j = 0; j <= n; j++)
        dp[0][j] = 0;

    // Fill DP table
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else if (dp[i - 1][j] >= dp[i][j - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i][j - 1];
        }
    }

    // Print LCS length
    printf("Length of LCS = %d\n", dp[m][n]);

    // Reconstruct LCS
    char lcs[100];
    index = dp[m][n];
    lcs[index] = '\0';

    i = m;
    j = n;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("Longest Common Subsequence = %s\n", lcs);

    return 0;
}
