#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int p[N] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
int q;

int CUT_ROD_rec(int n)
{
    if (n == 0)
        return 0;
    q = INT_MIN;

    for (int i = 0; i < n; i++)
        q = max(q, p[i] + CUT_ROD_rec(n - i - 1));

    return q;
}
int main()
{
    for (int i = 0; i < 10; i++)

        cout << CUT_ROD_rec(i) << "\n";

    // CUT_ROD_rec(4);
}
