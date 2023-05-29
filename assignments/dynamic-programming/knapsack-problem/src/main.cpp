#include "knapsack.hpp"
#include <iostream>

using namespace std;

int main(void) {
	vector<Item> items1 = {Item(10, 2), Item(7, 1), Item(25, 6), Item(24, 5)};
	vector<Item> items2 = {Item(10, 1), Item(40, 3), Item(50, 4), Item(70, 5)};

	long unsigned int maxWeight1 = 7;
	long unsigned int maxWeight2 = 7;

	int result1 = knapsackBottomUp(maxWeight1, items1);
	cout << "Resultado = " << result1 << endl;
	int result2 = knapsackBottomUp(maxWeight2, items2);
	cout << "Resultado = " << result2 << endl;
}
