#include <iostream>

using namespace std;

void LCSlength(int m, int n, char *x, char *y, int **c, int **b)
{
    for (int i = 0; i < m; i++)
    {
        c[i][0] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        c[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (x[i] == y[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else if (c[i - 1][j] > c[i][j - 1])
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
int main()
{
    int m, n;  // size of two sequences
    char *str1, *str2;
    int **seq_lengths, **paths;

    cout << "Enter the size of the first sequence: ";
    cin >> m;
    str1 = new char[m];
    cout << "Enter the first sequence: ";
    cin.getline(str1, m);

    cout << "Enter the size of the second sequence: " << endl;
    cin >> n;
    str2 = new char[n];
    cout << "Enter the first sequence: ";
    cin.getline(str2, n);

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



    return 0;
}
