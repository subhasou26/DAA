
#include <stdio.h>
#include <stdlib.h>

int method0(int *S, int n) {
    // Method 0: Brute force approach with O(n^4) time complexity
    for (int a = 0; a < n - 2; a++) {
        for (int b = a + 1; b < n - 1; b++) {
            for (int c = b + 1; c < n; c++) {
                // Find positions of a, b, and c in the sequence
                int i, j, k;
                for (i = 0; i < n; i++) {
                    if (S[i] == a) break;
                }
                for (j = 0; j < n; j++) {
                    if (S[j] == b) break;
                }
                for (k = 0; k < n; k++) {
                    if (S[k] == c) break;
                }
                // Check if i < j < k
                if (i < j && j < k) {
                    return 1; // algolicious
                }
            }
        }
    }
    return 0;
}

int method1(int *A, int n) {
    // Method 1: Approach with O(n^3) time complexity
    for (int a = 0; a < n - 2; a++) {
        for (int b = a + 1; b < n - 1; b++) {
            for (int c = b + 1; c < n; c++) {
                // Check if the current combination violates largest-smallest-intermediate pattern
                if (A[a] < A[b] && A[b] < A[c]) {
                    return 1; // 
                }
            }
        }
    }
    return 0; // 
}

int method2(int *S, int n) {
    // Method 2: Approach with O(n^2) time complexity
    for (int i = 0; i < n; i++) {
        int c = S[i];
        for (int j = i + 1; j < n; j++) {
            if (S[j] >= c) {
                return 0; // If any element after S[i] is greater than or equal to c, sequence is not algolicious
            }
            c = S[j]; // Update c for next iteration
        }
    }
    return 1; // If all subsequences are strictly decreasing, sequence is algolicious
}

int method3(int *A, int n) {
    // Method 3: Approach with O(n) time complexity
    int stack[n]; // Stack to store elements
    int top = -1; // Stack top pointer
    int largest = -1; // Initialize largest as -1
    for (int i = 0; i < n; i++) {
        // Check if the current element is less than largest
        if (A[i] < largest) {
            return 0; // Invalid
        }
        // Pop elements from stack until the top element is greater than the current element
        while (top != -1 && A[i] > stack[top]) {
            largest = stack[top--]; // Update largest
        }
        // Push current element to stack
        stack[++top] = A[i];
    }
    return 1; // Valid
}

int main(int argc, char *argv[]) {
    int i, n, *A;

    // Scan the input
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; ++i)
        scanf(" %d", &A[i]);

    printf("\n");
    printf("    Method 0: %s\n", method0(A, n) ? "Valid" : "Invalid");
    printf("    Method 1: %s\n", method1(A, n) ? "Valid" : "Invalid");
    printf("    Method 2: %s\n", method2(A, n) ? "Valid" : "Invalid");
    printf("    Method 3: %s\n", method3(A, n) ? "Valid" : "Invalid");

    free(A); // Free allocated memory
    return 0;
}

