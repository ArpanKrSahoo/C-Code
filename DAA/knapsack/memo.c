#include <stdio.h>
#include <string.h>


int dp[100][100];
int max(int a, int b){
    return (a>b)?a:b;
}
int knapsack(int W,int wt[], int val[],int n){
    if(n==0||W==0){
        return 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    if(wt[n-1]>W){
        return dp[n][W]=knapsack(W,wt,val,n-1);
    }
return dp[n][W]=max(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1));
}
int main(){
    int W=60;
    int wt[]={15,30,45};
    int val[]={60,100,150};
    int n=sizeof(val)/sizeof(val[0]);

    memset(dp,-1,sizeof(dp));
    printf("%d",knapsack(W,wt,val,n));
    return 0;
}