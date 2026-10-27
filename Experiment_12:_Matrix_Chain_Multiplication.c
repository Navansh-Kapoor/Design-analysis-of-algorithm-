
#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];

    printf("Enter %d dimensions: ", n + 1);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    int dp[n + 1][n + 1];

    // Cost of multiplying one matrix is zero
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    // len is the chain length
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum number of multiplications = %d\n",
           dp[1][n]);

    return 0;
}
