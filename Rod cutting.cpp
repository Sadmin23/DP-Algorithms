#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int CUT_ROD_rec(int p[], int n)
{
    if (n == 0)
        return 0;
    int q = INT_MIN;

    for (int i = 0; i < n; i++)
        q = max(q, p[i] + CUT_ROD_rec(p, n - i));

    return q;
}
int main()
{
    int p[N] = {1, 5, 8, 9, 10, 17, 20, 24, 30};
}