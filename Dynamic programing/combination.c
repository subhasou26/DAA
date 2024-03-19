#include <stdio.h>

void find_combinations(int amount, int coins[], int index, int current_combination[], int result[][10], int* result_index) {
    if (amount == 0) {
        for (int i = 0; i < index; i++) {
            result[*result_index][i] = current_combination[i];
        }
        (*result_index)++;
        return;
    }

    for (int i = index; i < 10; i++) {
        if (amount >= coins[i]) {
            current_combination[index] = coins[i];
            find_combinations(amount - coins[i], coins, index + 1, current_combination, result, result_index);
        }
    }
}

int main() {
    // Given denominations
    int denominations[] = {20, 10, 10, 5, 5, 2, 2, 1, 1, 1};

    // Total amount to be given as change
    int total_amount = 50 - 17;

    // Initialize variables
    int combinations[1000][10];  // Assuming a maximum of 1000 combinations with a maximum of 10 coins each
    int result_index = 0;

    // Find all combinations
    find_combinations(total_amount, denominations, 0, (int[]){0}, combinations, &result_index);

    // Print all combinations
    for (int i = 0; i < result_index; i++) {
        printf("Combination %d: ", i + 1);
        for (int j = 0; j < 10; j++) {
            if (combinations[i][j] != 0) {
                printf("%d ", combinations[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
