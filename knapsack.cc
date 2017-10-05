#include <iostream>
#include <vector>
using namespace std;

int knapsack(int W, vector<int> wt, vector<int> cost, int n) {
    if (n == 0 || W == 0) return 0;
    if (wt[n-1] > W) return knapsack(W, wt, cost, n-1);
    return max(knapsack(W, wt, cost, n-1),
               cost[n-1] + knapsack(W-wt[n-1], wt, cost, n-1)
               );
}

int main() {
    vector<int> wt = {4, 5, 2};
    vector<int> cost = {5, 2, 4};
    int W = 7;

    cout << "\nKnapsack:\n";
    cout << knapsack(W, wt, cost, wt.size()) << endl;
}
