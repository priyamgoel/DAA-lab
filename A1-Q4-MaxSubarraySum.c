#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

int ComputeMidL(int A[], int P, int m) {
    int Sum = 0;
    int maxSum = 0;

    for (int i = m; i >= P; i--) {
        Sum += A[i];
        if (Sum > maxSum) {
            maxSum = Sum;
        }
    }
    return maxSum;
}

int ComputeMidR(int A[], int m, int Q) {
    int Sum = 0;
    int maxSum = 0;

    for (int i = m + 1; i <= Q; i++) {
        Sum += A[i];
        if (Sum > maxSum) {
            maxSum = Sum;
        }
    }
    return maxSum;
}

int MaxSum(int A[], int P, int Q) {
    if (P == Q) {
        return max(0, A[P]);
    }

    int m = (P + Q) / 2;

    int maxL = MaxSum(A, P, m);
    int maxR = MaxSum(A, m + 1, Q);

    int maxMidL = ComputeMidL(A, P, m);
    int maxMidR = ComputeMidR(A, m, Q);

    int maxMid = maxMidL + maxMidR;

    return max3(maxL, maxR, maxMid);
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }

    int A[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int result = MaxSum(A, 0, n - 1);

    printf("\nMaximum Sum Subarray is: %d\n", result);

    return 0;
}
