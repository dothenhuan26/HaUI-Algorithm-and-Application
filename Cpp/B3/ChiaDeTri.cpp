#include <bits/stdc++.h>
using namespace std;

// 1 8 1 2 3 4 5 6 7 8
// 8 8 1 2 3 4 5 6 7 8
// 5 8 1 2 3 4 5 6 7 8
// 9 8 1 2 3 4 5 6 7 8
// 6 9 1 3 4 8 9 10 11 12 13

int binary_search(int a[], int l, int r, int x)
{
    if (l > r)
        return -1;
    int m = (l + r) / 2;
    if (a[m] == x)
        return m;
    else if (a[m] > x)
        binary_search(a, l, m - 1, x);
    else
        binary_search(a, m + 1, r, x);
}

int binary_search_by_loop(int a[], int n, int x)
{
    int l = 0, r = n - 1;
    do
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return m;
        else if (a[m] > x)
            r = m - 1;
        else
            l = m + 1;
    } while (l <= r);
    return -1;
}

int search_or_insert(int a[], int l, int r, int x)
{
    if (l > r)
        return l;
    int m = (l + r) / 2;
    if (a[m] == x)
        return m;
    else if (a[m] > x)
        return search_or_insert(a, l, m - 1, x);
    else
        return search_or_insert(a, m + 1, r, x);
}

int main()
{
    int x, n;
    cin >> x >> n;
    int a[n];
    for (auto &x : a)
        cin >> x;

    // cout << binary_search(a, 0, n - 1, x);
    cout << search_or_insert(a, 0, n - 1, x);

    return 0;
}