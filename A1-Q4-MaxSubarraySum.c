#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxOfThree(int a, int b, int c) {
    return max(max(a, b), c);
}

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    
    for (int i = mid; i >= low; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    int right_sum = INT_MIN;
    sum = 0;
    
    for (int i = mid + 1; i <= high; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int maxSubArraySum(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    return maxOfThree(
        maxSubArraySum(arr, low, mid),
        maxSubArraySum(arr, mid + 1, high),
        maxCrossingSum(arr, low, mid, high)
    );
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input size.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_sum = maxSubArraySum(arr, 0, n - 1);
    
    printf("Maximum Subarray Sum is: %d\n", max_sum);

    return 0;
}
