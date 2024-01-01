#include <bits/stdc++.h>
using namespace std;

long long res(int n)
{
    if (n <= 0)
        return 0;
    if (n % 2 == 0)
        return res(n - 1);
    return n + res(n - 2);
}

int main()
{
    cout << res(10) << endl;

    return 0;
}