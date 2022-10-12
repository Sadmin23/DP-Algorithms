#include <bits/stdc++.h>

int lis_rec(int arr[], int n, int *max_ref)
{
    if (n == 1)
        return 1;

    int res, end = 1;

    for (int i = 1; i < n; i++)
    {
        res = lis_rec(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1] && res + 1 > end)
            end = res + 1;
    }

    if (*max_ref < end)
        *max_ref = end;

    return end;
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
using namespace std;

int main()
{
}