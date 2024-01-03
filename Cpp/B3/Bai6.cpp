#include <bits/stdc++.h>
using namespace std;

// 10 1 2 3 4 5 6 7 8 9 10

long long sumOdds(int a[], int l, int r)
{
    if (l == r)
        return a[l] & 1 ? a[l] : 0;

    int m = (l + r) / 2;
    return sumOdds(a, l, m) + sumOdds(a, m + 1, r);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &x : a)
        cin >> x;
    cout << sumOdds(a, 0, n - 1) << endl;
    return 0;
}