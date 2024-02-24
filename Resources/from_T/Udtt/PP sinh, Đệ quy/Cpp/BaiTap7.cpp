#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;
int memo[MAX_SIZE]{0};

long long f(int n)
{
    if (n == 1 || n == 2)
        return 1;
    if (memo[n] != 0)
        return memo[n];
    memo[n] = f(n - 1) + f(n - 2);
    return memo[n];
}

int main()
{

    cout << f(18) << endl;

    return 0;
}