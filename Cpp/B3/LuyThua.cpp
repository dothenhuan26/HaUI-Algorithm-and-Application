#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Cho so nguyen duong N va K, tinh N^K modulo 10^9+7

ll mod = 1e9 + 7;

ll pow(int a, int k)
{
    if (k == 0)
        return 1;
    if (k == 1)
        return a;
    ll tmp = pow(a, k / 2);
    if (k & 1)
        return tmp * tmp * a;
    return tmp * tmp;
}

int main()
{
    int a, k;
    cin >> a >> k;
    cout << pow(a, k) << endl;
    return 0;
}