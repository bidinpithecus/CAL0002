#ifndef _KNAPSACK_HPP_
#define _KNAPSACK_HPP_

#include <vector>

struct Item {
	float value;
	float weight;

	Item(float value, float weight): value(value), weight(weight) {}
	Item(): value(0), weight(0) {}
};

std::vector<std::pair<Item, float>> fractionalKnapsack(float W, std::vector<Item>& arr);

#endif
