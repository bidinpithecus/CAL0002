#include "knapsack.hpp"
#include "sort.hpp"

using namespace std;

vector<pair<Item, float>> fractionalKnapsack(float W, vector<Item>& arr) {
	mergeSort(arr);

	vector<pair<Item, float>> quantities;
	float remainingWeight = W;

	for (long unsigned int i = 0; i < arr.size(); i++) {
		if (arr[i].weight <= remainingWeight) {
			quantities.push_back(make_pair(arr[i], 1.0));
			remainingWeight -= arr[i].weight;
		} else {
			quantities.push_back(make_pair(arr.at(i), (float) remainingWeight / arr[i].weight));
			break;
		}
	}

	return quantities;
}
