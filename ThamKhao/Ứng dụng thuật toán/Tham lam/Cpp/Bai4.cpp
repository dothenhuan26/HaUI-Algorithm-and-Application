#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> m >> n;
    int a[n];
    for (auto &x : a)
        cin >> x;

    sort(a, a + n, greater<int>());
    int cnt = 0;
    int i = 0;
    while (m > 0 && i != n)
    {
        cnt++;
        m -= a[i];
        i++;
    }
    if (m > 0)
        cout << "Khong du xe!" << endl;
    else
        cout << cnt << endl;

    return 0;
}