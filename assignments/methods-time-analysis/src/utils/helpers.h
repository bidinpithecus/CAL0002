#ifndef _HELPERS_H_
#define _HELPERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>

#define HEADER "Size,BubbleSort,InsertionSort,HeapSort,MergeSort,QuickSort,SequentialSearch,BinarySearch\n"

void swap(int v[], int i, int j);
void heapify(int v[], int n, int i);
void merge(int v[], int head, int half, int tail);
void halfMergeSort(int v[], int head, int tail);
unsigned int randomNum(int max);
unsigned long timeSortingRandomArrays(int v[], int n, int limit, int numArrays, void (*sortMethod)(int*, int));
unsigned long timeSearchingRandomArrays(int v[], int n, int limit, int numArrays, int key, int (*searchMethod)(int*, int, int), bool needsToBeOrdered);
int partition(int v[], int head, int tail);
void pivotQuickSort(int v[], int head, int tail);
int max(int v[], int n);
int cmpFunc (const void * a, const void * b);
void countingSort(int v[], int n, int exp);

#endif
