#include <bits/stdc++.h>
using namespace std;

void next_config(int a[], int n, int i)
{
    a[i] = 1;
    i++;
    while (i <= n)
    {
        a[i] = 0;
        i++;
    }
}

void view(int a[], int n)
{
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << endl;
}

void listing()
{
    int n;
    cin >> n;
    int a[n+1]{0};
    int i;
    do
    {
        i=n;
        view(a, n);
        while (i > 0 && a[i] == 1)
        {
            i--;
        }
        if (i > 0)
            next_config(a, n, i);
    } while (i > 0);
}

int main()
{
    // int n;
    // cin >> n;
    // int a[n]{0};
    // int i;
    // do {
    //     for(auto x:a) cout<<x;
    //     i=n-1;
    //     while(i>=0 && a[i]==1) {
    //         a[i]=0;
    //         i--;
    //     }
    //     a[i]=1;

    //     cout<<endl;
    // } while(i>=0);

    listing();

    return 0;
}