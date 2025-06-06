#include<stdio.h>

void quickSort(int arr[], int l, int h);
int partition(int arr[], int l, int h);

int main(void) {
    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Try again\n");
        return 0;
    }
    int arr[n];

    printf("Enter elements: \n");
    for (int i = 0; i < n; i++) {
	printf("For element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nSorted list:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void quickSort(int arr[], int l, int h) {
    if (l < h) {
        int j = partition(arr, l, h);
        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, h);
    }
}

int partition(int arr[], int l, int h) {
    int pivot = arr[l];
    int i = l;

    for (int j = l + 1; j <= h; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i];
    arr[i] = arr[l];
    arr[l] = temp;
    return i;
}
