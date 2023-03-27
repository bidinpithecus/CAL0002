#include "searches.h"

int sequentialSearch(int v[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (v[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int v[], int n, int item) {
    int begin = 0;
    int end = n - 1;

    while (begin <= end) {
        int i = (begin + end) / 2;
        if (v[i] == item) {
            return i;
        }

        if (v[i] < item) {
            begin = i + 1;
        } else {
            end = i;
        }
    }

    return -1;
}