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
    cout << "ROD CUTTING\n\n";

    // int N = 10;

    // int p[N] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    // int x = N;

    int N = rand() % 20 + 1;

    int p[N];

    for (int i = 0; i < N; i++)
    {
        int x = rand() % 50 + 1;

        p[i] = x;
    }

    int x = rand() % N + 1;

    cout << "Size of rod cuts: " << N << "\n\n";

    cout << "Values of rod cuts: ";

    for (int i = 0; i < N; i++)
        cout << p[i] << " ";

    cout << "\n\n";

    cout << "No. of maximized cuts: " << x << "\n\n";

    cout << "Recursion:\n";

    auto st = chrono::high_resolution_clock::now();

    cout << "Ans: " << CUT_ROD_rec(x, p) << "\n";

    auto ed = chrono::high_resolution_clock::now();

    auto dur = chrono::duration_cast<chrono::microseconds>(ed - st);

    cout << "Time required: " << dur.count() << " microseconds\n\n";

    cout << "Memoized:\n";

    auto st1 = chrono::high_resolution_clock::now();

    cout << "Ans: " << MEMOIZED_CUT_ROD(x, p) << "\n";

    auto ed1 = chrono::high_resolution_clock::now();

    auto dur1 = chrono::duration_cast<chrono::microseconds>(ed1 - st1);

    cout << "Time required: " << dur1.count() << " microseconds\n\n";

    cout << "Bottom_up:\n";

    auto st2 = chrono::high_resolution_clock::now();

    cout << "Ans: " << BOTTOM_UP_CUT_ROD(x, p) << "\n";

    auto ed2 = chrono::high_resolution_clock::now();

    auto dur2 = chrono::duration_cast<chrono::microseconds>(ed2 - st2);

    cout << "Time required: " << dur2.count() << " microseconds\n\n";
}