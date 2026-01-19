#include <stdio.h>

void solve() {
    unsigned long long n, h, w;
    if (scanf("%llu %llu %llu", &n, &h, &w) != 3) return;

    unsigned long long low = 1;
    unsigned long long high = 2000000000000000000ULL; 
    unsigned long long ans = high;

    while (low <= high) {
        unsigned long long mid = low + (high - low) / 2;
        unsigned long long itemsInWidth = mid / w;
        unsigned long long itemsInHeight = mid / h;

        int isValid = 0;
        if (itemsInWidth >= n || itemsInHeight >= n) {
            isValid = 1;
        } else if ((itemsInWidth * itemsInHeight) >= n) {
            isValid = 1;
        }

        if (isValid) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    printf("%llu\n", ans);
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
