#include <bits/stdc++.h>
using namespace std;

int n, a[100];

void init()
{
    for (int i = 1; i <= n; i++)
        a[i] = 0;
}

void view_config()
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << endl;
}

void gen_config()
{
    int i;
    do
    {
        i = n;
        view_config();

        while (i >= 1 && a[i] == 1)
        {
            a[i] = 0;
            i--;
        }
        if (i == 0)
            return;
        else
            a[i] = 1;
    } while (i >= 1);
}

int main()
{
    cin >> n;
    init();
    gen_config();

    return 0;
}