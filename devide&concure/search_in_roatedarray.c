#include <stdio.h>

int help(int arr[], int start, int end, int target)
{
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
        return mid;

    if (arr[start] <= arr[mid])
    { // hopping the element is in left part
        if (arr[start] <= target && target <= arr[mid])
        {                                             // in left part
            return help(arr, start, mid - 1, target); // searching in left part
        }
        else
        {
            return help(arr, mid + 1, end, target); // searching in right part
        }
    }
    else
    {
        if (target >= arr[mid] && target <= arr[end])
        { // in left part
            return help(arr, mid + 1, end, target);
        }
        else
        {
            return help(arr, start, mid - 1, target);
        }
    }
}

int main()
{
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
   int ans= help(arr, 0, 7, 1);
   if(ans!=-1){
    printf("the index is %d",ans);
   }
   else{
    printf("index not found");
   }
    return 0;
}