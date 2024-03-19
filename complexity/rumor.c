#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct {
   double hi;
   double lo;
} two_val;


double lorec(int n); // Declare lorec before hirec since hirec calls lorec



double hirec(int n) {
    if (n == 0) return 1;
    return 2 * hirec(n - 1) + lorec(n - 1);
}

double lorec(int n) {
    if (n == 0) return 0;
    return hirec(n - 1) + lorec(n - 1);
}

two_val hilorec(int n) {
    two_val N;
    N.hi = hirec(n);
    N.lo = lorec(n);
    return N;
}

two_val hiloformula(int n) {
    two_val N;
    N.hi = ((5 + sqrt(5)) / 10) * pow(((3 - sqrt(5)) / 2), n+1) 
     + ((5 - sqrt(5)) / 10) * pow(((3 + sqrt(5)) / 2), n+1);

    N.lo = ((-5 - 5*sqrt(5)) / 10 * pow((3 - sqrt(5)) / 2, n+1)) + 
      ((-5 + 3*sqrt(5)) / 10 * pow((3 + sqrt(5)) / 2, n+1));

    return N;
}

int main(int argc, char *argv[]) {
    two_val N1, N2, N3;
    int n;

    clock_t start, end;
    double cpu_time_used;

    scanf("%d", &n);
    printf("n = %d\n", n);

    printf("\n+++ Method 0\n");
    start = clock();
    N1.hi = hirec(n); N1.lo = lorec(n);
    end = clock();
    printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N1.hi, n, N1.lo);
    cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("Method 0 took %f seconds to execute \n", cpu_time_used);

    printf("\n+++ Method 1\n");
    start = clock();
    N2 = hilorec(n);
    end = clock();
    printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N2.hi, n, N2.lo);
    cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("Method 1 took %f seconds to execute \n", cpu_time_used);

    printf("\n+++ Method 2\n");
    start = clock();
    N3 = hiloformula(n);
    end = clock();
    printf("    hi(%d) = %.10le, lo(%d) = %.10le\n", n, N3.hi, n, N3.lo);
    cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("Method 2 took %f seconds to execute \n", cpu_time_used);

    exit(0);
}
