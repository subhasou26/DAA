#include <stdio.h>

double fn(double x) {
    return x*x*x - 10*x*x - 15*x - 20;
}

int find_first_positive_n() {
    double low = 0, high = 50;  // Assuming the range for n is [0, 10]

    while (high - low > 1e-6) {
        double mid = (low + high) / 2;

        if (fn(mid) > 0)
            high = mid;
        else
            low = mid;
    }

    return (int)(low + 1);  // Return the integer value of the first positive n
}

int main() {
    int result = find_first_positive_n();

    printf("The smallest positive n for which f(n) becomes positive is: %d\n", result);

    return 0;
}
