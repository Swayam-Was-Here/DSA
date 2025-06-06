#include<stdio.h>

void exchangeSort(int arr[], int n);

int main(void) {
    int n;
    printf("\nEnter the length of the array: ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("\nThe length of an array can't be negative or Zero!!\n");
        return 0;
    }

    int arr[n];

    printf("\nEnter the data to sort:\n");
    for (int i = 0; i < n; i++) {
        printf("For element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    exchangeSort(arr, n);
    printf("\nThe sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    
    }
    printf("\n\n");
}

void exchangeSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
    
} 