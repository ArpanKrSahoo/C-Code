#include <stdio.h>
#include<stdlib.h>
void printArray(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
    
}
int main(){
    int arr[]={7,8,3,1,2};
    int n =sizeof(arr)/sizeof(arr[0]);

    
    return 0;
}