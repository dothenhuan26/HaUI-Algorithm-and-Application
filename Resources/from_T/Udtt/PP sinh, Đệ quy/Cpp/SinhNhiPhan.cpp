#include <bits/stdc++.h>
using namespace std;

void sinhNhiPhan()
{
    int n, i;
    cin >> n;
    int a[n + 1]{0};
    do
    {
        for (int j = 1; j <= n; j++)
            cout << a[j];

        i = n;
        while (i >= 1 && a[i] == 1)
        {
            a[i] = 0;
            i--;
        }
        if (i >= 1)
            a[i] = 1;

        cout << endl;
    } while (i >= 1);
}

int main()
{
    sinhNhiPhan();

    return 0;
}