#include "methods/sorts.h"
#include "methods/searches.h"

#define MAX 5000
#define NUM_RANDOM_ARRAYS 15
#define EXECUTIONS 500
#define NUMBER_TO_BE_FOUND 100

int main(void) {
	srand((unsigned int) time(NULL));
	unsigned long time;
	int arraySize;
	int execsMade = 0;
	int *v = NULL;
	FILE *pAvg;

	pAvg = fopen("results/data.csv", "w+");

	if(pAvg == NULL) {
		perror("Error opening file.");
		exit(-1);
	}
	fprintf(pAvg, HEADER);
	do {
		arraySize = randomNum(MAX);
		v = (void*) malloc(sizeof(int) * arraySize);
		fprintf(pAvg, "%d,", arraySize);

		// inicio bubble sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, bubbleSort);
		fprintf(pAvg, "%ld,", time);
		// fim bubble sort

		// inicio insertion sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, insertionSort);
		fprintf(pAvg, "%ld,", time);
		// fim insertion sort

		// inicio heap sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, heapSort);
		fprintf(pAvg, "%ld,", time);
		// fim heap sort

		// inicio merge sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, mergeSort);
		fprintf(pAvg, "%ld,", time);
		// fim merge sort

		// inicio quick sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, quickSort);
		fprintf(pAvg, "%ld,", time);
		// fim quick sort

		// inicio sequential search
		time = timeSearchingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, NUMBER_TO_BE_FOUND, sequentialSearch, false);
		fprintf(pAvg, "%ld,", time);
		// fim sequential search

		// inicio binary search
		time = timeSearchingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, NUMBER_TO_BE_FOUND, binarySearch, true);
		fprintf(pAvg, "%ld", time);
		// fim binary search

		fprintf(pAvg, "\n");
		execsMade++;
	} while (execsMade != EXECUTIONS);
	free(v);

	fclose(pAvg);
	return 0;
}
