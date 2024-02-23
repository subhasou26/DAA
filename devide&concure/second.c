#include <stdio.h>

double fn(double x)
{
    return x * x * x - 10 * x * x - 15 * x - 20;
}
int find_max()
{
    double rand = 1;
    while (fn(rand) < 0)
    {

        rand = rand + rand * 2;
    }
    return rand;
}
int find_min()
{
    double rand = 100;
    while (fn(rand) > 0)
    {

        rand = rand - (rand / 2);
    }
    return rand;
}

int find_first_positive_n(double low, double high)
{

    while (high - low > 1e-6)
    {
        double mid = (low + high) / 2;

        if (fn(mid) > 0)
            high = mid;
        else
            low = mid;
    }

    return (int)(low + 1); // Return the integer value of the first positive n
}

int main()
{
    // int result = find_first_positive_n();
    int result = find_min();
    int result1 = find_max();
    printf("Min: %d\n", result);
    printf("Max %d\n", result1);
    int ans = find_first_positive_n(result, result1);
    printf("%d\n", ans);
    return 0;
}
