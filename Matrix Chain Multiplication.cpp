#include <bits/stdc++.h>

using namespace std;

int m[100][100], s[100][100];

#define INF INT_MAX

void matrix_chain_order(vector<int> p)
{
    int n = p.size() - 1;

    m[n][n];
    s[n - 1][n - 1;]

        for (int i = 0; i < n; i++)
            m[i][i] = 0;

    for (int l = 1; l < n; l++)
    {
        for (int i = 0; i < n - l - 1; i++)
        {
            int j = i + l - 1;

            m[i][j] = INF;

            for (int k = i; k < j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k] * p[j];

                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
int main()
{
}