#include<stdio.h>

int subsetSum(int arr[],int n,int sum){
    int dp[n+1][sum+1];

    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }

    for(int i=1;i<=sum;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }   else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }

    return dp[n][sum];
}

int main(){
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (subsetSum(arr, n, sum))
        printf("Subset with given sum exists\n");
    else
        printf("No subset found\n");

    return 0;

}