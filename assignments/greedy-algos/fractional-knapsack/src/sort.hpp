#ifndef _SORT_HPP_
#define _SORT_HPP_

#include <vector>
#include <iostream>
#include "knapsack.hpp"

bool cmp(Item a, Item b);
void merge(std::vector<Item>& arr, int const begin, int const end);
void halfMergeSort(std::vector<Item>& arr, int const left, int const mid, int const right);
void mergeSort(std::vector<Item>& arr);

#endif
