#include <bits/stdc++.h>
using namespace std;

void bai2()
{
    int n, i;
    cin >> n;
    char a[n + 1];
    for (int j = 1; j <= n; j++)
        a[j] = 'a';

    do
    {
        for (int j = 1; j <= n; j++)
            cout << a[j];
        i = n;
        while (i >= 1 && a[i] == 'b')
        {
            a[i] = 'a';
            i--;
        }
        if (i >= 1)
            a[i] = 'b';

        cout << endl;
    } while (i >= 1);
}

int main()
{
    bai2();

    return 0;
}