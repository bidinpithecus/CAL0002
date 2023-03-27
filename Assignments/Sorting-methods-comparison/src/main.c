#include "sorts.h"
#include "searches.h"

#define MAX 100
#define NUM_RANDOM_ARRAYS 10
#define EXECUTIONS 2
#define NUMBER_TO_BE_FIND 10

int main(void) {
	srand(time(NULL));
	int time;
	int arraySize;
	int execsMade = 0;
	int *v = NULL;
	FILE *pAvg;

	pAvg = fopen("results/avg.txt", "a");

	if(pAvg == NULL) {
		perror("Error opening file.");
		exit(-1);
	}
	do {
		arraySize = randomNum(MAX);
		v = malloc(sizeof(int) * arraySize);
		fprintf(pAvg, "%d\t", arraySize);

		// inicio bubble sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, bubbleSort);
		printf("%d\t", time);
		fprintf(pAvg, "%d\t", time);
		// fim bubble sort

		// inicio insertion sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, insertionSort);
		printf("%d\t", time);
		fprintf(pAvg, "%d\t", time);
		// fim insertion sort

		// inicio heap sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, heapSort);
		printf("%d\t", time);
		fprintf(pAvg, "%d\t", time);
		// fim heap sort

		// inicio merge sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, mergeSort);
		printf("%d\t", time);
		fprintf(pAvg, "%d\t", time);
		// fim merge sort

		// inicio quick sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, quickSort);
		printf("%d\t", time);
		fprintf(pAvg, "%d\t", time);
		// fim quick sort

		// inicio sequential search
		time = timeSearchingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, NUMBER_TO_BE_FIND, sequentialSearch);
		printf("%d\t", time);
		fprintf(pAvg, "%d\t", time);
		// fim sequential search

		// inicio binary search
		time = timeSearchingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, NUMBER_TO_BE_FIND, binarySearch);
		printf("%d\t", time);
		fprintf(pAvg, "%d\t", time);
		// fim binary search

		execsMade++;
	} while (execsMade != EXECUTIONS);
	free(v);

	fclose(pAvg);
	return 0;
}
