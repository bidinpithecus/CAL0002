#include "sort.hpp"

using namespace std;

bool cmp(Item a, Item b) {
	double ratio1 = (double) a.value / a.weight;
	double ratio2 = (double) b.value / b.weight;

	return ratio1 > ratio2;
}

void mergeSort(vector<Item>& arr) {
    merge(arr, 0, arr.size() - 1);
}

void merge(vector<Item>& arr, int const begin, int const end) {
    if (begin >= end) {
        return;
    }

    auto mid = begin + (end - begin) / 2;
    merge(arr, begin, mid);
    merge(arr, mid + 1, end);
    halfMergeSort(arr, begin, mid, end);
}

void halfMergeSort(vector<Item>& arr, int const left, int const mid, int const right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    vector<Item> leftArray;
    vector<Item> rightArray;

    for (auto i = 0; i < subArrayOne; i++) {
        leftArray.push_back(arr[left + i]);
    }

    for (auto j = 0; j < subArrayTwo; j++) {
        rightArray.push_back(arr[mid + 1 + j]);
    }

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (cmp(leftArray.at(indexOfSubArrayOne), rightArray.at(indexOfSubArrayTwo))) {
            arr.at(indexOfMergedArray) = leftArray.at(indexOfSubArrayOne);
            indexOfSubArrayOne++;
        } else {
            arr.at(indexOfMergedArray) = rightArray.at(indexOfSubArrayTwo);
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        arr.at(indexOfMergedArray) = leftArray.at(indexOfSubArrayOne);
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        arr.at(indexOfMergedArray) = rightArray.at(indexOfSubArrayTwo);
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

