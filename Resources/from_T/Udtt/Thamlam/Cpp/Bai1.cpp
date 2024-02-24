#include <bits/stdc++.h>
using namespace std;

int c[5] = {100, 25, 10, 5, 1};
int cnt = 0;
int s[5]{0};
void calc(int n)
{
    for (int i = 0; i < 5; i++)
    {
        s[i] = n / c[i];
        cnt += s[i];

        n %= c[i];
    }
}

int main()
{
    int n;
    cin >> n;
    calc(n);
    cout << cnt << endl;
    for (auto x : s)
        cout << x << " ";

    return 0;
}