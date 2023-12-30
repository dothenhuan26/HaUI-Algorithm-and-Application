#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = i;
    do
    {
        i = n - 1;
        for (int i = 1; i <= n; i++)
            cout << a[i];
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

    return 0;
}