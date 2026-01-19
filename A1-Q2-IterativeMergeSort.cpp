#include <stdio.h>

void Merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2]; 

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void IMergeSort(int A[], int n) {
    int curr_size;
    int left_start;

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            
            int mid = left_start + curr_size - 1;
            
            if (mid >= n - 1) continue;

            int right_end = left_start + 2 * curr_size - 1;
            if (right_end >= n) {
                right_end = n - 1;
            }

            Merge(A, left_start, mid, right_end);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    IMergeSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
