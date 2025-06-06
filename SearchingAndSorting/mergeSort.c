#include<stdio.h>
#include<stdlib.h>


void merge(int arr[], int l, int m, int r);

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

    
    printf("\nSORTED list\n");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


void merge(int arr[], int l, int m, int r) {

}