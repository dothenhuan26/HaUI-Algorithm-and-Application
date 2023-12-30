#include <bits/stdc++.h>
using namespace std;

void sinhXauNhiPhan()
{
    int n, i;
    cin >> n;
    int a[n + 1]{0};

    do
    {
        for (int i = 1; i <= n; i++)
            cout << a[i];
        i = n;
        while (i >= 1 && a[i] == 1)
        {
            a[i] = 0;
            i--;
        }
        if (i >= 1)
        {
            a[i] = 1;
        }

        cout << endl;
    } while (i >= 1);
}

void sinhToHop()
{
    int n, k, i;
    cin >> n >> k;
    int a[k+1];
    for (int i = 1; i <= k; i++)
        a[i] = i;

    do
    {
        for (int i = 1; i <= k; i++)
            cout << a[i];
        i = k;
        while (i >= 1 && a[i] == n - k + i)
            i--;
        if (i >= 1)
        {
            a[i]++;
            for (int j = i + 1; j <= k; j++)
            {
                a[j] = a[j - 1] + 1;
            }
        }

        cout << endl;
    } while (i >= 1);
}

void sinhHoanVi()
{
    int n, i;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = i;
    do
    {
        for (int i = 1; i <= n; i++)
            cout << a[i];

        i = n - 1;
        while (i >= 1 && a[i] > a[i + 1])
            i--;
        if (i >= 1)
        {
            int j = n;
            while (a[i] > a[j])
                j--;
            swap(a[i], a[j]);
            int r = n;
            i++;
            while (i < r)
            {
                swap(a[i], a[r]);
                i++;
                r--;
            }
        }

        cout << endl;
    } while (i >= 1);
}

int main()
{
    // sinhXauNhiPhan();
    sinhToHop();
    // sinhHoanVi();

    return 0;
}