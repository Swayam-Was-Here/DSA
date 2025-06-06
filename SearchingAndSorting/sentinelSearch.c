#include<stdio.h>


int sentinelSearch(int arr[], int n, int x);

int main(void) {
    int n, x;
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("Enter reasonable length for the array!\n");
        return 0;
    }

    int arr[n];

    printf("\nEnter data for the array: \n");
    for (int i = 0; i < n; i++) {
        printf("For element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("\nEnter the element to search: ");
    scanf("%d", &x);

    int result = sentinelSearch(arr, n, x);

    if (result != -1) {
        printf("\n%d is present at index %d\n\n", x, result);
    } else {
        printf("\nElement not found\n");
    }
    return 0;
}

int sentinelSearch(int arr[], int n, int x) {

    int last = arr[n - 1];
    arr[n - 1] = x;
    int i = 0;

    while (arr[i] != x) {
        i++;
    }

    arr[n - 1] = last;

    if (i < n - 1 || last == x) {
        return i;
    } else {
        return -1;
    }
}