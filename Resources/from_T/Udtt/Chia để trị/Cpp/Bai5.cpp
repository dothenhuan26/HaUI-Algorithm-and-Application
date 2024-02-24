#include <bits/stdc++.h>
using namespace std;

double negSum(double a[], int l, int r)
{
    if (l >= r)
        return a[l] > 0 ? a[l] : 0;
    int m = (l + r) / 2;
    double left = negSum(a, l, m);
    double right = negSum(a, m + 1, r);
    if (left > 0 && right > 0)
        return left + right;
    return left > 0 ? left : (right > 0 ? right : 0);
}

int main()
{
    double a[20] = {-5.4, 11.2, 49.12, 28.64, -11.4,
                    -4.9, 8.112, 21.12, 9.1001, 41.23,
                    -19.41, 2.15, -91.2, 12.13, -52.1,
                    55.9, 6.8, -11.12, 31.4, 22.19};

    cout << negSum(a, 0, 19) << endl;

    return 0;
}