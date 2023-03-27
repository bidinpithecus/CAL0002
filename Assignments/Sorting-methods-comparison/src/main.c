#include "sorts.h"
#include "searches.h"

#define MAX 1000
#define NUM_RANDOM_ARRAYS 10
#define EXECUTIONS 50
#define NUMBER_TO_BE_FOUND 100

int main(void) {
	srand((unsigned int) time(NULL));
	unsigned long time;
	int arraySize;
	int execsMade = 0;
	int *v = NULL;
	FILE *pAvg;

	pAvg = fopen("results/avg.txt", "w+");

	if(pAvg == NULL) {
		perror("Error opening file.");
		exit(-1);
	}
	fprintf(pAvg, HEADER);
	do {
		arraySize = randomNum(MAX);
		v = malloc(sizeof(int) * arraySize);
		fprintf(pAvg, "%d\t", arraySize);

		// inicio bubble sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, bubbleSort);
		fprintf(pAvg, "%ld\t", time);
		// fim bubble sort

		// inicio insertion sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, insertionSort);
		fprintf(pAvg, "%ld\t", time);
		// fim insertion sort

		// inicio heap sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, heapSort);
		fprintf(pAvg, "%ld\t", time);
		// fim heap sort

		// inicio merge sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, mergeSort);
		fprintf(pAvg, "%ld\t", time);
		// fim merge sort

		// inicio quick sort
		time = timeSortingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, quickSort);
		fprintf(pAvg, "%ld\t", time);
		// fim quick sort

		// inicio sequential search
		time = timeSearchingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, NUMBER_TO_BE_FOUND, sequentialSearch);
		fprintf(pAvg, "%ld\t", time);
		// fim sequential search

		// inicio binary search
		time = timeSearchingRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, NUMBER_TO_BE_FOUND, binarySearch);
		fprintf(pAvg, "%ld\t", time);
		// fim binary search

		fprintf(pAvg, "\n");
		execsMade++;
	} while (execsMade != EXECUTIONS);
	free(v);

	fclose(pAvg);
	return 0;
}
