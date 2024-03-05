#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100

// Function to find the minimum number of multiplications needed to multiply matrices
int matrixChainMultiplication(int dims[], int n) {
    int dp[MAX_SIZE][MAX_SIZE]; // Dynamic programming table

    // Initialize the table with -1
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    // Base case: the cost of multiplying one matrix is 0
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    // Fill the table in a bottom-up manner
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n];
}

int main() {
    int dims[] = {10,20,30}; // Example dimensions, change as needed
    int n = sizeof(dims) / sizeof(dims[0]) - 1; // Number of matrices

    int minMultiplications = matrixChainMultiplication(dims, n);
    
    printf("Minimum number of multiplications: %d\n", minMultiplications);

    return 0;
}
