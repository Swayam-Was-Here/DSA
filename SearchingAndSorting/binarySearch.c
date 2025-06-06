#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x);

int main(){
    int n;
    printf("Enter the lenght of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The lenght of the array can't be 0 or negative!\n");
        return 0;
    }

    int arr[n];

    printf("\nEnter sorted data:\n");
    for (int i = 0; i < n; i++) {
        printf("for element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    int toSearch;
    printf("\nEnter the element to search in the array: ");
    scanf("%d", &toSearch);
    
    int result = binarySearch(arr, 0, n - 1, toSearch);
    if (result == -1) {
        printf("Element is not present in array\n");
    } else {    
        printf("Element is present at index %d\n", result);
    }
        return 0;
}

int binarySearch(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        
        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        return binarySearch(arr, mid + 1, high, x);
    }

    return -1;
}