#include <bits/stdc++.h>
using namespace std;

int bottles(int n, int m, int x[])
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        sum += n / x[i];
        if (n / x[i] > 0)
            n %= x[i];
    }
    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int x[m];
    for (auto &i : x)
        cin >> i;
    sort(x, x + m, greater<int>());
    cout << bottles(n, m, x) << endl;

    return 0;
}