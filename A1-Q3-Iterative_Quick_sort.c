#include <stdio.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void iterativeQuickSort(int arr[], int n) {
    int stack[2 * n];
    int top = -1;

    top++;
    stack[top] = 0;
    top++;
    stack[top] = n - 1;

    while (top >= 0) {
        int high = stack[top];
        top--;
        int low = stack[top];
        top--;

        int m = partition(arr, low, high);

        if (m - 1 > low) {
            top++;
            stack[top] = low;
            top++;
            stack[top] = m - 1;
        }

        if (m + 1 < high) {
            top++;
            stack[top] = m + 1;
            top++;
            stack[top] = high;
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    iterativeQuickSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
