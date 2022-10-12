#include <bits/stdc++.h>

using namespace std;

int lis_rec_max(int arr[], int n, int *max_ref)
{
    if (n == 1)
        return 1;

    int res, end = 1;

    for (int i = 1; i < n; i++)
    {
        res = lis_rec_max(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1] && res + 1 > end)
            end = res + 1;
    }

    if (*max_ref < end)
        *max_ref = end;

    return end;
}
int lis_rec(int arr[], int n)
{
    int max = 1;

    lis_rec_max(arr, n, &max);

    return max;
}
int lis_bottom_up(int arr[], int n)
{
    int lis[n];

    lis[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    return *max_element(lis, lis + n);
}
int lis_memo(int arr[], int n)
{
    vector<int> b;
    set<int> s;

    set<int>::iterator it;

    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    for (it = s.begin(); it != s.end(); it++)
    {
        b.push_back(*it);
    }
    int m = b.size(), i, j;
    int dp[m + 1][n + 1];

    for (i = 0; i < m + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (i = 0; i < m + 1; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (arr[j - 1] == b[i - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    cout << "LONGSET INCREASING SUBSEQUENCE\n\n";

    // int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    // int n = sizeof(arr) / sizeof(arr[0]);

    int n = rand() % 10 + 1;

    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100 + 1;

    cout << "Size of array: " << n << "\n\n";

    cout << "Array: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\n";

    cout << "Recursion:\n";

    auto st = chrono::high_resolution_clock::now();

    cout << "Ans: " << lis_rec(arr, n) << "\n";

    auto ed = chrono::high_resolution_clock::now();

    auto dur = chrono::duration_cast<chrono::microseconds>(ed - st);

    cout << "Time required: " << dur.count() << " microseconds\n\n";

    auto st1 = chrono::high_resolution_clock::now();

    cout << "Ans: " << lis_bottom_up(arr, n) << "\n";

    auto ed1 = chrono::high_resolution_clock::now();

    auto dur1 = chrono::duration_cast<chrono::microseconds>(ed1 - st1);

    cout << "Time required: " << dur1.count() << " microseconds\n\n";

    auto st2 = chrono::high_resolution_clock::now();

    cout << "Ans: " << lis_memo(arr, n) << "\n";

    auto ed2 = chrono::high_resolution_clock::now();

    auto dur2 = chrono::duration_cast<chrono::microseconds>(ed2 - st2);

    cout << "Time required: " << dur1.count() << " microseconds\n\n";
}