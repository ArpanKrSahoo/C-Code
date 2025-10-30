#include <stdio.h>

void merge(int arr1[],int arr2[],int arr3[],int n1,int n2){
    int i ,j ,k;
    i=j=k=0;

    while (i<n1 && j<n2)
    {
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }
        else{
            arr3[k++]=arr2[j++];
        }
    }

    //copy remaining elements
    while(i<n1){
        arr3[k++]=arr1[i++];
    }
    while(j<n2){
        arr3[k++]=arr2[j++];
    }
    for(int m=0;m<n1+n2;m++){
        printf("%d ",arr3[m]);
    }

};

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        //merge(arr,l,m,r);
    }
}

int main(){
    int arr1[]={7,3,3,53,36,46};
    int arr2[]={4,6,9,10,12,15,20};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    int arr3[n1+n2];
    merge(arr1,arr2,arr3,n1,n2);
    
    return 0;
}