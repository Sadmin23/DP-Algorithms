#include <bits/stdc++.h>

using namespace std;

int m[100][100];
int s[100][100];
int A[100][100][100];
pair<int, int> dim[100];

int indx;
string seq = "";

void matrix_mult(int a, int b)
{
    int x = dim[a].first;
    int y = dim[b].second;
    int z = dim[a].second;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
                A[indx][i][j] = A[indx][i][j] + A[a][i][k] * A[b][k][j];
        }
    }
    dim[indx] = {x, y};

    // cout << x << " " << y << "\n";
}
int matrix_bottom_up(int p[], int n)
{
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
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    return m[1][n - 1];
}
void optimal(int i, int j)
{
    if (i == j)
    {
        seq = seq + to_string(i - 1);

        printf("A%d", i);
    }
    else
    {
        printf("(");
        seq.push_back('(');
        optimal(i, s[i][j]);
        optimal(s[i][j] + 1, j);
        seq.push_back(')');
        printf(")");
    }
}
string mult(string s)
{
    stack<char> st;
    string result = "";

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c >= '0' && c <= '9')
            st.push(c);
        else if (c == '(')
            st.push('(');
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            result += "*";

            st.pop();
        }
    }
    return result;
}
int mult2(string s)
{
    stack<int> ans;

    int flag = 0;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if (c >= '0' && c <= '9')
        {
            ans.push(c - '0');
            flag = 0;
        }
        else if (c == '*')
        {
            int a = ans.top();
            ans.pop();

            int b = ans.top();
            ans.pop();

            indx++;

            if (flag == 0)
                matrix_mult(a, b);
            else
                matrix_mult(b, a);

            cout << a << " " << b << "\n";

            ans.push(indx);

            flag = 1;
        }
    }

    return ans.top();
}
int main()
{
    memset(A, 0, sizeof(A));

    int n = 5;
    // n = rand() % 10 + 1;

    int p[n] = {3, 4, 2, 4, 3};

    // for (int i = 0; i < n; i++)
    // {
    //     int a = rand() % 10 + 1;

    //     p[i] = a;
    // }

    for (int i = 0; i < n - 1; i++)
        dim[i] = {p[i], p[i + 1]};

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < p[i]; j++)
        {
            for (int k = 0; k < p[i + 1]; k++)
            {
                A[i][j][k] = rand() % 10 + 1;
            }
        }
    }

    indx = n - 2;

    cout << n << "\n";

    for (int i = 0; i < n; i++)
        cout << p[i] << " ";

    puts("\n");

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < p[i]; j++)
        {
            for (int k = 0; k < p[i + 1]; k++)
            {
                printf("%d ", A[i][j][k]);
            }
            puts("");
        }
        puts("\n");
    }

    cout << matrix_bottom_up(p, n) << "\n";

    puts("");

    optimal(1, n - 1);

    puts("");

    int x = mult2(mult(seq));

    for (int i = 0; i < dim[x].first; i++)
    {
        for (int j = 0; j < dim[x].second; j++)
        {
            cout << A[x][i][j] << " ";
        }

        puts("");
    }

    return 0;
}