#include <bits/stdc++.h>

using namespace std;

int knapsack_rec(int W, int w[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if (w[n - 1] > W)
        return knapsack_rec(W, w, val, n - 1);
    else
        return max(val[n - 1] + knapsack_rec(W - w[n - 1], w, val, n - 1), knapsack_rec(W, w, val, n - 1));
}
int main()
{
    int N = 3;

    int val[N] = {60, 100, 120};
    int w[N] = {10, 20, 30};

    int W = 50;

    cout << knapsack_rec(W, w, val, N) << "\n";

    return 0;
}