#include <bits/stdc++.h>
using namespace std;

int findMax(int a[], int l, int r)
{
    if (l == r)
        return a[l];
    int m = (l + r) / 2;
    int left = findMax(a, l, m);
    int right = findMax(a, m + 1, r);
    int max = std::max(left, right);

    return max;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &x : a)
        cin >> x;

    cout << findMax(a, 0, n - 1);

    return 0;
}