#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double pow(double a, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    double half = pow(a, n / 2);
    if (n & 1)
        return half * half * a;
    return half * half;
}

int main()
{
    double a;
    int n;
    cin >> a >> n;

    cout << pow(a, n);

    return 0;
}