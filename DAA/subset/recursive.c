#include <stdio.h>

int subsetSumRecursive(int arr[], int n, int sum) {

    if (sum == 0)
        return 1;

    if (n == 0)
        return 0;

    if (arr[n - 1] > sum)
        return subsetSumRecursive(arr, n - 1, sum);

    return subsetSumRecursive(arr, n - 1, sum) ||
           subsetSumRecursive(arr, n - 1, sum - arr[n - 1]);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (subsetSumRecursive(arr, n, sum))
        printf("Subset with given sum exists\n");
    else
        printf("No subset found\n");

    return 0;
}