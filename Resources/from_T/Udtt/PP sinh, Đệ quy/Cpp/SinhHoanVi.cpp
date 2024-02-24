#include <bits/stdc++.h>
using namespace std;

void sinhHoanVi()
{
    int n, i;
    cin >> n;
    int a[n + 1];
    for (int j = 1; j <= n; j++)
        a[j] = j;
    do
    {
        for (int j = 1; j <= n; j++)
            cout << a[j];
        i = n - 1;
        while (i >= 1 && a[i] > a[i + 1])
            i--;
        if (i >= 1)
        {
            int j = n;
            while (a[i] > a[j])
                j--;
            swap(a[i], a[j]);
            i++;
            int r = n;
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
    sinhHoanVi();
    return 0;
}