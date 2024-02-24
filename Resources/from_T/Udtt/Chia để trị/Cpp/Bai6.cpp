#include <bits/stdc++.h>
using namespace std;

int findEvenMin(int a[], int l, int r)
{
    if (l >= r)
        return a[l];
    int m = (l + r) / 2;
    int left = findEvenMin(a, l, m);
    int right = findEvenMin(a, m + 1, r);
    if (!(left & 1) && !(right & 1))
    {
        return std::min(left, right);
    }
    return !(left & 1) ? left : (!(right & 1) ? right : -1);
}

int main()
{
    int a[20] = {9, 5, 7, 2, 12,
                 32, 63, 11, 8, 14,
                 4, 1, 21, 65, 15,
                 61, 17, 84, 53, 78};

    cout << findEvenMin(a, 0, 19) << endl;

    return 0;
}