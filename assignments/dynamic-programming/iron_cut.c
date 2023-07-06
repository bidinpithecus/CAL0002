#include <stdio.h>
#include <stdlib.h>

int bottomUpIronCut(int* arr, int size);
int topDownHelper(int* arrA, int* arrB, int size);
int topDownIronCut(int* arr, int size);

int bottomUpIronCut(int* arr, int size) {
	int arrB[size];

	for (int i = 0; i < size; i++) {
		int profit = arr[i];

		for (int j = 0; j < i; j++) {
			int value = arr[j] + arrB[i - j - 1];

			if (value > profit) {
				profit = value;
			}
		}
		arrB[i] = profit;
	}

	return arrB[size - 1];
}

int topDownHelper(int* arrA, int* arrB, int size) {
	if (arrB[size] == -1) {
		int profit = arrA[size];

		for (int i = 1; i < size; i++) {
	 		int value = arrA[i] + topDownHelper(arrA, arrB, size - i - 1);

			if (value > profit) {
				profit = value;
			}
		}
		arrB[size] = profit;
	}

	return arrB[size];
}

int topDownIronCut(int* arr, int size) {
	int arrB[size];
	arrB[0] = arr[0];

	for (int i = 1; i < size; i++) {
		arrB[i] = -1;
	}

	return topDownHelper(arr, arrB, size - 1);
}

int main(void) {
	int arr[] = {1, 3, 11, 16, 19, 10};
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	printf("Bottom-Up-Approach-Iron-Cut(%d) = %d\n", arrSize, bottomUpIronCut(arr, arrSize));
	printf("Top-Down-Approach-Iron-Cut(%d) = %d\n", arrSize, topDownIronCut(arr, arrSize));

	return 0;
}
