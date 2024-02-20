#include <stdio.h>

// Function declaration
void towerOfHanoi3(int n, int from, int to, int aux);

// Function to move disks from peg 'from' to peg 'to' using pegs 'aux1', 'aux2'
void towerOfHanoi4(int n, int from, int to, int aux1, int aux2) {
    if (n == 0) {
        return;
    }

    if (n == 1) {
        printf("Move disk 1 from peg %d to peg %d\n", from, to);
        return;
    }

    int k = n / 2; // Best value for k

    // Move k disks from peg 'from' to peg 'aux1' using pegs 'aux2', 'to'
    towerOfHanoi4(k, from, aux1, aux2, to);

    // Move n-k disks from peg 'from' to peg 'to' using peg 'aux2'
    towerOfHanoi3(n - k, from, to, aux2);

    // Move nth disk from peg 'from' to peg 'to'
    printf("Move disk %d from peg %d to peg %d\n", n, from, to);

    // Move n-k disks from peg 'aux2' to peg 'to' using pegs 'from', 'aux1'
    towerOfHanoi3(n - k, aux2, to, from);

    // Move n-k disks from peg 'aux2' to peg 'to' using pegs 'from', 'aux1'
    towerOfHanoi4(k, aux1, to, from, aux2);
}

// Function to move disks from peg 'from' to peg 'to' using peg 'aux'
void towerOfHanoi3(int n, int from, int to, int aux) {
    if (n == 0) {
        return;
    }

    if (n == 1) {
        printf("Move disk 1 from peg %d to peg %d\n", from, to);
        return;
    }

    // Move n-1 disks from peg 'from' to peg 'aux' using peg 'to'
    towerOfHanoi3(n - 1, from, aux, to);

    // Move nth disk from peg 'from' to peg 'to'
    printf("Move disk %d from peg %d to peg %d\n", n, from, to);

    // Move n-1 disks from peg 'aux' to peg 'to' using peg 'from'
    towerOfHanoi3(n - 1, aux, to, from);
}

int main() {
    int n = 2; // Number of disks
    int peg1 = 1, peg2 = 2, peg3 = 3, peg4 = 4;

    printf("Tower of Hanoi with 4 pegs:\n");
    towerOfHanoi4(n, peg1, peg2, peg3, peg4);

    return 0;
}
