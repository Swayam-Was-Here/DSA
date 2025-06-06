#include<stdio.h>

void swap(int* xp, int* yp);
void bubbleSort(int arr[], int n);


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

    bubbleSort(arr, n);
    printf("\nThe sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    
    }
    printf("\n\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
        
    }
    
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
