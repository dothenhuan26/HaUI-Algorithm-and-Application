#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[m];
    int cnt = 0;

    for (auto &x : a)
        cin >> x;
    sort(a, a + m);
    for (auto x : a)
    {
        if (n - x == 0 || n - x > x)
        {
            n -= x;
            cnt++;
        }
    }
    if (n == 0)
        cout << cnt;
    else
        cout << "Khong do day binh duoc!";

    return 0;
}