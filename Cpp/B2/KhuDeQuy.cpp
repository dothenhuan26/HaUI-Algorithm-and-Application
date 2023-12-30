#include <bits/stdc++.h>
using namespace std;

long f(int n)
{
    long res = 1, fn1 = 1, fn2 = 1;
    for (int i = 3; i <= n; i++)
    {
        res = fn1 + fn2;
        fn2 = fn1;
        fn1 = res;
    }
    return res;
}

int main()
{
    cout << f(18) << endl;
    return 0;
}