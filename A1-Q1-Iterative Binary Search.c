#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; 

        // Check if x is present at mid
        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] < x) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    // Element is not present
    return -1;
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n) ;

    int arr[n];
    printf("Enter %d sorted elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, n, x);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element is not present\n");
    }

    return 0;
}
