#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 102
#define MOD 1e9+7
int dp[MAX_SIZE][MAX_SIZE];
int a[MAX_SIZE];
// Function to find the minimum number of multiplications needed to multiply matrices
/*int matrixChainMultiplication(int dims[], int n) {
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

    // Fill the table in a bottom-up manner digonaly
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
}*/

// dynamic prograin approach

int mcm(int i,int j){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=MOD; 
    
    for(int k=i;k<j;k++){
        int ans=mcm(i,k)+mcm(k+1,j)+a[i-1]*a[k]*a[j];
        if(dp[i][j]>ans){
            dp[i][j]=ans;
        }
    }
    return dp[i][j];
}

int main() {
     // Example dimensions, change as needed
     // Number of matrices

   // int minMultiplications = matrixChainMultiplication(dims, n);
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

   for(int i=0;i<MAX_SIZE;i++){
    for( int j=0;j<MAX_SIZE;j++){
        dp[i][j]=-1; // initilizing dp array with -1
    }
   }

   int ans=mcm(1,n-1);
    
   // printf("Minimum number of multiplications: %d\n", minMultiplications);
    printf("The ans is %d",ans);
    return 0;
}
