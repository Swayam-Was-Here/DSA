#include<stdio.h>


int insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main(void) {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Enter reasonable size for the array!!\n\n");
        return 0;
    }

    int arr[n];
    printf("\nEnter data:\n");
    for (int i = 0; i < n; i++) {
        printf("For element %d:  ", i + 1);
        scanf("%d" , &arr[i]);
    }

    insertionSort(arr, n);
    printArray(arr, n);
}

int insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    printf("\nSORTED list\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}