
#include <stdio.h>
#include <stdlib.h>

int x[20], n;

// Check whether queen can be placed safely
int place(int k, int col) {
    for (int i = 1; i < k; i++) {
        if (x[i] == col ||
            abs(x[i] - col) == abs(i - k))
            return 0;
    }
    return 1;
}

// Backtracking function
void nQueens(int k) {
    for (int col = 1; col <= n; col++) {
        if (place(k, col)) {
            x[k] = col;

            if (k == n) {
                // Print solution
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (x[i] == j)
                            printf("Q ");
                        else
                            printf(". ");
                    }
                    printf("\n");
                }
                printf("\n");
            } else {
                nQueens(k + 1);
            }
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Enter n between 1 and 20.\n");
        return 0;
    }

    printf("Solutions:\n");
    nQueens(1);

    return 0;
}
