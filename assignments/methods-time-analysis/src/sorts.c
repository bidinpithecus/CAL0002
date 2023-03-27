#include "sorts.h"

void bubbleSort (int v[], int n) {
	
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] > v[j]) {
				swap(v, i, j);
			}
		}
	}
}

void insertionSort(int v[], int n) {
	int center, j;

	for (int i = 1; i < n; i++) {
		center = v[i];
		j = i - 1;

		while (j >= 0 && center < v[j]) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = center;
	}
}

void heapSort(int v[], int n) {
	int i;

	for (i = (n / 2) - 1; i >= 0; i--) {
		heapify(v, n, i);
	}
	for (i = n - 1; i > 0; i--) {
		swap(v, 0, i);
		heapify(v, i, 0);
	}
}

void mergeSort(int v[], int size) {
	halfMergeSort(v, 0, size - 1);
}

void quickSort(int v[], int size) {
	pivotQuickSort(v, 0, size - 1);
}
