#include<stdio.h>

void ssort(int arr[], int n);

int main(void) {
    int n;
    printf("Enter length of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Enter a natural number for the length of the array\n");
        return 0;
    }
    int arr[n];
    printf("\nEnter unsorted values for each element of the array:\n");

    for (int i = 0; i < n; i++) {
        printf("For element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    ssort(arr, n);

    printf("\nThe sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void ssort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}