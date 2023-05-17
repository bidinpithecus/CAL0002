#include <iostream>
#include "knapsack.hpp"
#include "sort.hpp"

using namespace std;

void printArray(vector<Item> A) {
	cout << "{ ";
	for (auto item : A) {
		cout << "(" << item.value << ", " << item.weight << "), ";
	}
	cout << "};" << endl;
}

int main() {
    vector<Item> items = {Item(840, 40), Item(600, 30), Item(400, 20), Item(100, 10), Item(300, 20)};
    float weightCapacity = 50.0;

    vector<pair<Item, float>> quantities = fractionalKnapsack(weightCapacity, items);
	float totalValue(0);

	printArray(items);

    cout << "(Item, Quantity): " << endl;
    for (long unsigned int i = 0; i < quantities.size(); i++) {
        cout << "(" << quantities[i].first.value << ", " << quantities[i].second << ")" << endl;
		totalValue += quantities[i].first.value * quantities[i].second;
	}

	cout << "Max value: " << totalValue << endl;
    return 0;
}
