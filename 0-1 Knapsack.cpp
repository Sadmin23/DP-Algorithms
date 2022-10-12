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
int knapsack_memo(int W, int w[], int val[], int n)
{
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = W; j >= 0; j--)
        {

            if (w[i - 1] <= j)
                dp[j] = max(dp[j],
                            dp[j - w[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}
int main()
{

    // int N = 3;

    // int val[N] = {60, 100, 120};
    // int w[N] = {10, 20, 30};

    int N = rand() % 10 + 3;
    int val[N], w[N];

    for (int i = 0; i < N; i++)
    {
        int a = rand() % 30 + 1;

        val[i] = a * 10;

        int b = rand() % 3 + 1;

        w[i] = b * 10;
    }

    int W = 50;

    cout << N << "\n";

    for (int i = 0; i < N; i++)
        cout << val[i] << " ";
    puts("");

    for (int i = 0; i < N; i++)
        cout << w[i] << " ";
    puts("");
    // auto st = chrono::high_resolution_clock::now();

    // cout << knapsack_rec(W, w, val, N) << "\n";

    // auto ed = chrono::high_resolution_clock::now();

    // auto dur = chrono::duration_cast<chrono::microseconds>(ed - st);

    // cout << dur.count() << "\n";

    // auto st1 = chrono::high_resolution_clock::now();

    // cout << knapsack_bottom_up(W, w, val, N) << "\n";

    // auto ed1 = chrono::high_resolution_clock::now();

    // auto dur1 = chrono::duration_cast<chrono::microseconds>(ed1 - st1);

    // cout << dur1.count() << "\n";

    // auto st2 = chrono::high_resolution_clock::now();

    // cout << knapsack_memo(W, w, val, N) << "\n";

    // auto ed2 = chrono::high_resolution_clock::now();

    // auto dur2 = chrono::duration_cast<chrono::microseconds>(ed2 - st2);

    // cout << dur2.count() << "\n";

    return 0;
}