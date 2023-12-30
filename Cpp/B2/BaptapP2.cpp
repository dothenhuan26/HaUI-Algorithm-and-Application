#include <bits/stdc++.h>
using namespace std;

// const int MAX_SIZE = 100;
// int memo[MAX_SIZE]{0};

// long long f(int n)
// {
//     if (n == 1 || n == 2)
//         return 1;
//     if (memo[n] != 0)
//         return memo[n];
//     memo[n] = f(n - 1) + f(n - 2);
//     return memo[n];
// }

// void bai1()
// {
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cout << f(i) << " ";
//     }
// }

const int SIZE = 12;
const int n = 0, m = 5;
int x[SIZE][SIZE];
bool flag[SIZE][SIZE];
int countRef = 0, k;
// int x[5][6] = {{1, 1, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 1, 0}, {0, 1, 1, 0, 0, 1}, {0, 0, 1, 0, 1, 1}};
// bool flag[5][6];

void initialValues()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            x[i][j] = n + rand() % (m - n + 1);
            flag[i][j] = false;
        }
}

void loang(int i, int j)
{
    // if (i < 0 || j < 0)
    //     return;
    flag[i][j] = true;
    if ((x[i - 1][j] == x[i][j]) && x[i][j] == k && (!flag[i - 1][j]))
    {
        if (i - 1 < 0 || j < 0)
            return;
        countRef++;
        loang(i - 1, j);
    }
    if ((x[i + 1][j] == x[i][j]) && x[i][j] == k && (!flag[i + 1][j]))
    {
        if (i + 1 < 0 || j < 0)
            return;
        countRef++;
        loang(i + 1, j);
    }
    if ((x[i][j - 1] == x[i][j]) && x[i][j] == k && (!flag[i][j - 1]))
    {
        if (i < 0 || j - 1 < 0)
            return;
        countRef++;
        loang(i, j - 1);
    }
    if ((x[i][j + 1] == x[i][j]) && x[i][j] == k && (!flag[i][j + 1]))
    {
        if (i < 0 || j + 1 < 0)
            return;
        countRef++;
        loang(i, j + 1);
    }
}

int main()
{
    cin >> k;
    initialValues();

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 6; j++)
    //     {
    //         cout << x[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < 5; i++)
    //     for (int j = 0; j < 6; j++)
    //         loang(i, j);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << x[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            loang(i, j);

    cout << countRef << endl;

    return 0;
}