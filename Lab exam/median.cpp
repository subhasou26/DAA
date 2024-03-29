#include <bits/stdc++.h>
using namespace std;
double median_array(int arr1[],int arr2[],int n,int m){
   

    int merge[n+m];

    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            merge[k]=arr1[i];
            i++;
        }
        else{
            merge[k]=arr2[j];
            j++;
        }
        k++;
    }

    while(i<n){
        merge[k]=arr1[i];
        i++;k++;
    }
    while(j<m){
        merge[k]=arr2[j];
        j++;k++;
    }

    if((n+m)%2!=0){
        return merge[(n+m)/2];
    }
    else{
        int x=(n+m)/2;
        double p=merge[x];
        double q=merge[x-1];
        return (p+q)/2;
    }

}
int main()
{
    int arr1[]={2, 3, 5, 8, 10,11};
    int arr2[]={1, 4, 6, 7, 9, 11};
    int n=sizeof(arr1)/sizeof(int);
    int m=sizeof(arr2)/sizeof(int);
    cout<<median_array(arr1,arr2,n,m);
    return 0;
}