#ifndef _HELPERS_H_
#define _HELPERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void swap(int v[], int i, int j);
void heapify(int v[], int n, int i);
void merge(int v[], int head, int half, int tail);
void halfMergeSort(int v[], int head, int tail);
int randomNum(int max);
unsigned long timeSortingRandomArrays(int arr[], int size, int limit, int numArrays, void (*sortMethod)(int*, int));
unsigned long timeSearchingRandomArrays(int arr[], int size, int limit, int numArrays, int key, int (*searchMethod)(int*, int, int));
void sortedArray(int arr[], int size);
void sortedBackwardsArray(int arr[], int size);
int partition(int v[], int head, int tail);
void pivotQuickSort(int v[], int head, int tail);
int max(int v[], int n);
void countingSort(int v[], int n, int exp);

#endif