#include <bits/stdc++.h>
using namespace std;

void sinhToHop()
{
    int i, n, k;
    cin >> n >> k;
    int a[k + 1];
    for (int j = 1; j <= k; j++)
        a[j] = j;
    do
    {
        for (int j = 1; j <= k; j++)
            cout << a[j];
        i = k;
        while (i >= 1 && a[i] == n - k + i)
            i--;
        if (i >= 1)
        {
            a[i]++;
            i++;
            while (i <= k)
            {
                a[i] = a[i - 1] + 1;
                i++;
            }
        }
        cout << endl;
    } while (i >= 1);
}

int main()
{
    sinhToHop();
    return 0;
}