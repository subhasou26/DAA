#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void countingSort(int arr[], int n, int j, int k) {
    int count[k+1];  // we know k is the largst
            // Output array to store sorted values

    //initializing 0
    for(int i=0;i<k+1;i++){
        count[i]=0;
    }

    // stroing frequency
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    // sorting
    // this is counting array
    int q=0;//index for original array
    for(int i=0;i<k+1;i++){
        while(count[i]>0){
            arr[q]=i;
            q++;
            count[i]--;
        }
    }

}
int* generateArray(int n, int j, int k) {
    // Check if the input values are valid
    if (n <= 0 || j <= 1 || k <= j || k >= n) {
        printf("Invalid input parameters\n");
        return NULL;
    }

    // Allocate memory for the array
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // the randome ness depend on the current time
    srand(time(NULL));
//j + rand() % (k - j + 1);
    // Generate the array elements
    for (int i = 0; i < n; i++) {
        arr[i] = j + rand() % (k - j + 1);
    }

    return arr;
}

int main() {
    int n ,j,k;  // You can change the value of n as per your requirement j<e<k
    printf("Enter size of the array j and k\n");
    scanf("%d %d %d",&n,&j,&k);

   
    int* result = generateArray(n, j, k);

    if (result != NULL) {
        printf("Generated array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");

        // Don't forget to free the allocated memory
    }
    countingSort(result,n,j,k);
     if (result != NULL) {
        printf("Generated array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
        free(result);
        // Don't forget to free the allocated memory
    }

    return 0;
}
