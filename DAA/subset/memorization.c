#include<stdio.h>
#include<string.h>

int dp[100][100];

int subsetSum(int arr[], int n, int sum) {
    if (sum == 0)
        return 1;

    if (n == 0)
        return 0;

    if (dp[n][sum]!= -1)
        return dp[n][sum];

    if (arr[n-1] > sum)
        return dp[n][sum] = subsetSum(arr, n-1, sum);
    
    
    return dp[n][sum] = subsetSum(arr, n-1, sum) || 
                        subsetSum(arr, n-1, sum-arr[n-1]);
}


int  main(){
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof(dp));

    if (subsetSum(arr, n, sum))
        printf("Subset with given sum exists\n");
    else
        printf("No subset found\n");

    return 0;
}