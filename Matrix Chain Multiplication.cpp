#include <bits/stdc++.h>

using namespace std;

int memo[100][100];

int matrix_recusrion(int p[], int i, int j)
{
    if (i == j)
        return 0;

    int k, m = INT_MAX, q;

    for (k = i; k < j; k++)
    {
        q = matrix_recusrion(p, i, k) + matrix_recusrion(p, k + 1, j) + p[i - 1] * p[k] * p[j];

        m = min(q, m);
    }

    return m;
}
int matrix_memo_aux(int *p, int i, int j)
{
    if (i == j)
        return 0;

    if (memo[i][j] != -1)
        return memo[i][j];

    memo[i][j] = INT_MAX;

    for (int k = i; k < j; k++)
    {
        memo[i][j] = min(memo[i][j],
                         matrix_memo_aux(p, i, k) + matrix_memo_aux(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
    }
    return memo[i][j];
}
int matrix_memo(int *p, int n)
{
    int i = 1, j = n - 1;

    return matrix_memo_aux(p, i, j);
}
int matrix_bottom_up(int p[], int n)
{
    int m[n][n];

    int i, j, k, L, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}
int main()
{
    int n = 4;

    int p[4] = {10, 100, 5, 50};

    cout << matrix_recusrion(p, 1, n - 1) << "\n";

    memset(memo, -1, sizeof(memo));

    cout << matrix_memo(p, n) << "\n";

    cout << matrix_bottom_up(p, n) << "\n";

    return 0;
}