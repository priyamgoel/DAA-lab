#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == x) {
        return mid;
    }
    if (arr[mid] > x) {
        return binarySearch(arr, low, mid - 1, x);
    }
    return binarySearch(arr, mid + 1, high, x);
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);

    if (result == -1) {
        printf("Element is not present \n");
    } else {
        printf("Element found at index %d\n", result);
    }

    return 0;
}
