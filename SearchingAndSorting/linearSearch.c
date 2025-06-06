#include <stdio.h>

int main(void) {
    int n, toSearch, flag = 1;

    printf("Enter desired length of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter value for each element: \n");
    
    for (int i = 0; i < n; i++) {
        printf("element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &toSearch);

    for (int i = 0; i < n; i++) {
        if (arr[i] == toSearch) {
            printf("%d was found at position %d\n", toSearch, i + 1);
            flag--;
            break;
        }
    }

    if (flag) {
        printf("%d not found in the array\n", toSearch);
    }
    
    return 0;
}