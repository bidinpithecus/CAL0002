#include "searches.h"

int sequentialSearch(int v[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (v[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int v[], int n, int x){
	int l = 0;
    while (l <= n) {
        int m = l + (n - l) / 2;

        // Check if x is present at mid
        if (v[m] == x) {
            return m;
		}

        // If x greater, ignore left half
        if (v[m] < x) {
            l = m + 1;
		}

        // If x is smaller, ignore right half
        else {
            n = m - 1;
		}
    }

    // if we reach here, then element was
    // not present
    return -1;
}
