#include <bits/stdc++.h>

using namespace std;

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
int main()
{
    int n = 4;

    int p[4] = {10, 100, 5, 50};

    cout << matrix_recusrion(p, 1, n - 1) << "\n";

    return 0;
}