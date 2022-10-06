#include <bits/stdc++.h>

using namespace std;

int CUT_ROD_rec(int n, int p[])
{
    if (n == 0)
        return 0;
    int q = INT_MIN;

    for (int i = 1; i <= n; i++)
        q = max(q, p[i - 1] + CUT_ROD_rec(n - i, p));
    return q;
}
int MEMOIZED_CUT_ROD_AUX(int n, int r[], int p[])
{
    int q;

    if (r[n] >= 0)
        return r[n];

    if (n == 0)
        q = 0;
    else
        q = INT_MIN;

    for (int i = 1; i <= n; i++)
        q = max(q, p[i - 1] + MEMOIZED_CUT_ROD_AUX(n - i, r, p));
    r[n] = q;

    return q;
}
int MEMOIZED_CUT_ROD(int n, int p[])
{
    int r[n];

    for (int i = 0; i <= n; i++)
        r[i] = INT_MIN;

    return MEMOIZED_CUT_ROD_AUX(n, r, p);
}
int BOTTOM_UP_CUT_ROD(int n, int p[])
{
    int r[n + 1];

    r[0] = 0;

    int q;

    for (int j = 1; j <= n; j++)
    {
        q = INT_MIN;

        for (int i = 1; i <= j; i++)
            q = max(q, p[i - 1] + r[j - i]);

        r[j] = q;
    }

    return r[n];
}
int main()
{
    const int N = rand() % 20 + 1;

    int p[N];

    for (int i = 0; i < N; i++)
    {
        int x = rand() % 50 + 1;

        p[i] = x;
    }

    int x = rand() % N + 1;

    cout << CUT_ROD_rec(x, p) << "\n";

    cout << MEMOIZED_CUT_ROD(x, p) << "\n";

    cout << BOTTOM_UP_CUT_ROD(x, p) << "\n";
}