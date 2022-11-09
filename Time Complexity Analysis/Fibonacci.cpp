#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

int fib_rec(int n)
{
    if (n < 2)
        return n;
    else
        return fib_rec(n - 1) + fib_rec(n - 2);
}
int fib_dp(int n)
{
    int fib[n + 1];

    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}
void dur(int n)
{
    printf("FOR N = %d:\n", n);

    auto st = chrono::high_resolution_clock::now();

    cout << "FIB RECCURSION     value: " << fib_rec(n) << "   time: ";

    auto ed = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(ed - st);

    cout << duration.count() << " microseconds\n";

    auto st2 = chrono::high_resolution_clock::now();

    cout << "FIB DP             value: " << fib_dp(n) << "   time: ";

    auto ed2 = chrono::high_resolution_clock::now();

    auto duration2 = chrono::duration_cast<chrono::microseconds>(ed2 - st2);

    cout << duration2.count() << " microseconds\n\n";
}
int main()
{

    for (int i = 5; i < 50; i += 5)
        dur(i);

    //    dur(10);
    //    dur(5);

    return 0;
}