#ifndef _KNAPSACK_HPP_
#define _KNAPSACK_HPP_

#include <vector>

struct Item {
	int value;
	int weight;

	Item(int value, int weight): value(value), weight(weight) {}
	Item(): value(0), weight(0) {}
};

int knapsackBottomUp(long unsigned int knapsackSupportedWeight, std::vector<Item>& arr);

#endif
