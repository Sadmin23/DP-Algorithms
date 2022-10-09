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
int knapsack_bottom_up(int W, int w[], int val[], int n)
{
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || w == 0)
                K[i][j] = 0;
            else if (w[i - 1] <= j)
                K[i][j] = max(val[i - 1] + K[i - 1][j - w[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }

    return K[n][W];
}
int main()
{
    int N = 3;

    int val[N] = {60, 100, 120};
    int w[N] = {10, 20, 30};

    int W = 50;

    cout << knapsack_rec(W, w, val, N) << "\n";
    cout << knapsack_bottom_up(W, w, val, N) << "\n";

    return 0;
}