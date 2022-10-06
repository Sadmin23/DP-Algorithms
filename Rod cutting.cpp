#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int p[N] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

int CUT_ROD_rec(int n)
{
    if (n == 0)
        return 0;
    int q = INT_MIN;

    for (int i = 1; i <= n; i++)
    {
        int x = p[i - 1] + CUT_ROD_rec(n - i);

        if (x > q)
            q = x;
    }
    return q;
}
int MEMOIZED_CUT_ROD_AUX(int n, int r[])
{
    int q;

    if (r[n] >= 0)
        return r[n];

    if (n == 0)
        q = 0;
    else
        q = INT_MIN;

    for (int i = 1; i <= n; i++)
        q = max(q, p[i] + MEMOIZED_CUT_ROD_AUX(n - i, r));
    r[n] = q;

    return q;
}
int MEMOIZED_CUT_ROD(int n)
{
    int r[n];

    for (int i = 0; i < n; i++)
        r[i] = INT_MIN;

    return MEMOIZED_CUT_ROD_AUX(n, r);
}
int main()
{
    cout << CUT_ROD_rec(4) << "\n";
    cout << MEMOIZED_CUT_ROD(4) << "\n";
}
