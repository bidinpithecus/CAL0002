#include "knapsack.hpp"
#include <iostream>
#include <vector>

using namespace std;

int knapsackBottomUp(unsigned long supportedWeight, vector<Item>& items) {
    size_t numItems = items.size() + 1;
    supportedWeight++;
    vector<vector<int>> mat(numItems, vector<int>(supportedWeight, 0));

    for (size_t j = 1; j < numItems; j++) {
        for (unsigned long x = 1; x < supportedWeight; x++) {
            int maxWithoutCurr = mat[j - 1][x];

            if (items[j - 1].weight > x) {
                mat[j][x] = maxWithoutCurr;
            } else {
                int maxWithCurr = items[j - 1].value + mat[j - 1][x - items[j - 1].weight];
                mat[j][x] = max(maxWithCurr, maxWithoutCurr);
            }
        }
    }

    cout << "Matrix:" << endl;
    for (size_t j = 0; j < numItems; j++) {
        for (unsigned long x = 0; x < supportedWeight; x++) {
            cout << mat[j][x] << "\t";
        }
        cout << endl;
    }

    return mat[numItems - 1][supportedWeight - 1];
}
