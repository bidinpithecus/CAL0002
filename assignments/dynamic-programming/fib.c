#include <stdio.h>
#include <stdlib.h>

int topDownFibonacci(int n, int results[]);
int bottomUpFibonacci(int n);

int topDownFibonacci(int n, int results[]) {
	if (n == 1 || n == 2) {
		return 1;
	}
	if (results[n]) {
		return results[n];
	}
	return results[n] = topDownFibonacci(n - 1, results) + topDownFibonacci(n - 2, results);
}

int bottomUpFibonacci(int n) {
	int results[n];
	results[1] = 1;
	results[2] = 1;
	for (int i = 3; i < n; i++) {
		results[i] = results[i - 1] + results[i - 2];
	}
	return results[n];
}

int main(int argc, char** argv) {
	int num = 6;
	int results[num];

	for (int i = 0; i < num; i++) {
		results[i] = 0;
	}

	printf("Bottom-Up-Approach-Fibonacci(%d) = %d\n", num, bottomUpFibonacci(num));
	printf("Top-Down-Approach-Fibonacci(%d) = %d\n", num, topDownFibonacci(num, results));
	return 0;
}
