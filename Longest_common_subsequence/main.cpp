#include <iostream>
#include <cstdlib>
#include <cstdio>

#define N 25

using namespace std;

int read_line(char str[], int n);
void LCSlength(int m, int n, char *x, char *y, int **c, int **b);
void LCSseq(int i, int j, char *x, int **b);

int main()
{
    int m, n;  // size of two sequences
    char str1[N], str2[N];
    int **seq_lengths, **paths;

    cout << "Enter the first sequence: ";
    m = read_line(str1, N) + 1;

    cout << "Enter the first sequence: ";
    n = read_line(str2, N) + 1;

    // allocate memory for array seq_lengths and paths
    seq_lengths = new int*[m];
    paths = new int*[m];
    for (int i = 0; i < m; i++)
    {
        seq_lengths[i] = new int[n];
        paths[i] = new int[n];
    }

    LCSlength(m, n, str1, str2, seq_lengths, paths);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << seq_lengths[i][j] << "\t";
        }
        cout << "\n";
    }

    // print the longest common sequence
    LCSseq(m - 1, n - 1, str1, paths);

    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while (isspace(ch = getchar()))
           ;
    while (ch != '\n' && ch != EOF)
    {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}

void LCSlength(int m, int n, char *x, char *y, int **c, int **b)
{
    for (int i = 0; i < m; i++)
    {
        c[i][0] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        c[0][i] = 0;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else if (c[i - 1][j] >= c[i][j - 1])
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 3;
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 2;
            }
        }
    }
}

void LCSseq(int i, int j, char *x, int **b)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 1)
    {
        LCSseq(i - 1, j - 1, x, b);
        cout << x[i - 1];
    }
    else if (b[i][j] == 2)
    {
        LCSseq(i, j - 1, x, b);
    }
    else
    {
        LCSseq(i - 1, j, x, b);
    }
}
