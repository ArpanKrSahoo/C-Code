
#include <stdio.h>

void printSubset(int subset[],int subsetSize){
    printf("{ ");
    for(int i=0;i<subsetSize;i++){
        printf("%d ",subset[i]);
    }
    printf(" }\n");
}

void subsetSum(int arr[],int n, int sum,int index,int subset[],int subsetSize){
    
    if(sum==0){
        printSubset(subset,subsetSize);
        return;
    }
    if(index==n ||sum<0)
    return;
    
    subset[subsetSize]=arr[index];
    //include
    subsetSum(arr,n,sum-arr[index],index+1,subset,subsetSize+1);
    //exclude
    subsetSum(arr,n,sum,index+1,subset,subsetSize);
}
int main() {
    
    int arr[]={1,2,3,4,5,6,7};
    int n=7;
    int sum=14;
    
    int subset[100];
    printf("Subset:");
    subsetSum(arr,n,sum,0,subset,0);
    return 0;
}