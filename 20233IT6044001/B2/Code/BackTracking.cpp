#include <bits/stdc++.h>
using namespace std;

int a[100], n = 3;
bool dd[100];

void view()
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << endl;
}

void Try(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (dd[i] != 1)
        {
            a[k] = i;
            dd[i] = 1;

            if (k == n)
                view();
            else
                Try(k + 1);
                dd[i] = 0;
        }
    }
}

int main()
{
    memset(dd, false, sizeof 100);
    Try(1);

    return 0;
}