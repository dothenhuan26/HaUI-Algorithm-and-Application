#include <bits/stdc++.h>
using namespace std;

int x[5][6] = {{1, 1, 0, 0, 0, 1}, {1, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 1, 0}, {0, 1, 1, 0, 0, 1}, {0, 0, 1, 0, 1, 1}};
// int x[5][6] = {{1, 1, 1, 0, 0, 1}, {1, 0, 0, 1, 1, 0}, {0, 0, 1, 1, 0, 1}, {1, 1, 1, 1, 1, 1}, {0, 0, 1, 1, 0, 0}};
int cnt = 0;
bool flag[5][6];

void loang(int i, int j)
{
    if (x[i][j] != 1)
        return;
    if (i < 0 || j < 0)
        return;
    flag[i][j] = true;
    if (x[i][j - 1] == x[i][j] && !flag[i][j - 1])
    {
        j--;
        if (j < 0)
            return;
        cnt++;
        loang(i, j);
    }
    if (x[i - 1][j] == x[i][j] && !flag[i - 1][j])
    {
        i--;
        if (i < 0)
            return;
        cnt++;
        loang(i, j);
    }
    if (x[i][j + 1] == x[i][j] && !flag[i][j + 1])
    {
        cnt++;
        loang(i, j + 1);
    }
    if (x[i + 1][j] == x[i][j] && !flag[i + 1][j])
    {
        cnt++;
        loang(i + 1, j);
    }
}

int main()
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            loang(i, j);
        }
    }

    cout << cnt << endl;

    return 0;
}