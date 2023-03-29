#include "helpers.h"

struct timeval startTime, endTime;

// função que dado um vetor e dois indices, faz a troca dos elementos dos indices dados do vetor
void swap(int v[], int i, int j) {
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

// função auxiliar do Heap Sort
// função que recebe o vetor, seu tamanho, e o indice do pivo ("subarvore" a ser analisada)
void heapify(int v[], int n, int i) {
	int center = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < n && v[left] > v[center]) {
		center = left;
	}
	if (right < n && v[right] > v[center]) {
		center = right;
	}
	if (center != i) {
		swap(v, i, center);
		heapify(v, n, center);
	}
}

// função auxiliar do Merge Sort
void merge(int v[], int head, int half, int tail) {
	int* aux = malloc((tail - head + 1) * sizeof(int));
	int i = head, j = half + 1, k = 0;

	while (i <= half && j <= tail) {
		aux[k++] = v[i] <= v[j] ? v[i++] : v[j++];
	}

	while (i <= half) {
		aux[k++] = v[i++];
	}

	while (j <= tail) {
		aux[k++] = v[j++];
	}

	for (int i = head, k = 0; i <= tail; i++, k++) {
		v[i] = aux[k];
	}

	free(aux);
}

// função auxiliar do Merge Sort
void halfMergeSort(int v[], int head, int tail) {
	// Encontra o meio
 	int half = (head + tail) / 2;

 	if(head < tail) {
		// Metade superior
 		halfMergeSort(v, head, half);
		// Metade inferior
 		halfMergeSort(v, half + 1, tail);
		merge(v, head, half, tail);
	}
}

// funcao que gera um numero pseudo-aleatorio
unsigned int randomNum(int max) {
	FILE* fPtr;
	unsigned int num;

	fPtr = fopen("/dev/random", "r");
	fread(&num, sizeof(num), 1, fPtr);
	fclose(fPtr);

	num %= max + 1;

	return num;
}

unsigned long timeSortingRandomArrays(int v[], int n, int limit, int numArrays, void (*sortMethod)(int*, int)) {
	unsigned long microSec = 0;
	unsigned long timeDiff;

	for (int i = 0; i < numArrays; i++) {
		for (int j = 0; j < n; j++) {
			v[j] = randomNum(limit);
		}

		gettimeofday(&startTime, NULL);
		sortMethod(v, n);
		gettimeofday(&endTime, NULL);
		timeDiff = (1000000L * endTime.tv_sec + endTime.tv_usec) - (1000000L * startTime.tv_sec + startTime.tv_usec);
		microSec += timeDiff;
	}
	return microSec / numArrays;
}

unsigned long timeSearchingRandomArrays(int v[], int n, int limit, int numArrays, int key, int (*searchMethod)(int*, int, int), bool needsToBeOrdered) {
	unsigned long microSec = 0;
	unsigned long timeDiff;

	for (int i = 0; i < numArrays; i++) {
		for (int j = 0; j < n; j++) {
			v[j] = randomNum(limit);
		}

		if (needsToBeOrdered) {
			qsort(v, n, sizeof(int), cmpFunc);
		}

		gettimeofday(&startTime, NULL);
		searchMethod(v, n, key);
		gettimeofday(&endTime, NULL);
		timeDiff = (1000000L * endTime.tv_sec + endTime.tv_usec) - (1000000L * startTime.tv_sec + startTime.tv_usec);
		microSec += timeDiff;
	}
	return microSec / numArrays;
}

// Funcao que particiona o array do quick sort (Dividir e conquistar)
int partition(int v[], int head, int tail) {
	int last = v[tail];
	int i = (head - 1);

	for (int  j = head; j <= tail - 1; j++) {
		if (v[j] < last) {
			i++;
			swap(v, i, j);
		}
	}
	swap(v, i + 1, tail);
	return i + 1;
}

// Funcao que olha a divisão do array entre antes e depois do pivot
void pivotQuickSort(int v[], int head, int tail) {
	if (head < tail) {
		int middle = partition(v, head, tail);
		pivotQuickSort(v, head, middle - 1); //antes do pivot
		pivotQuickSort(v, middle + 1, tail); //depois do pivot
	}
}

// Função que pega o maior elemento de um vetor
int max(int v[], int n) {
  int max = v[0];
  for (int i = 1; i < n; i++)
    if (v[i] > max)
      max = v[i];
  return max;
}

int cmpFunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void countingSort(int v[], int n, int exp) {
	int* output = malloc((n + 1) * sizeof(int));
	int* count = malloc((10) * sizeof(int));

	for (int i = 0; i < n; i++){
 		count[(v[i] / exp) % 10]++;
	}

 	for (int i = 1; i < 10; i++){
 		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
 		output[count[(v[i] / exp) % 10] - 1] = v[i];
 		output[(v[i] / exp) % 10]--;
 	}

 	for (int i = 0; i < n; i++){
 		v[i] = output[i];
	}

	free(output);
	free(count);
}
