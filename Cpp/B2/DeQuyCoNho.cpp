#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100;
int memo[MAX_SIZE][MAX_SIZE];

long long C(int k, int n)
{
    if (k == 0 || k == n)
        return 1;

    if (memo[k][n] != -1)
        return memo[k][n];

    memo[k][n] = C(k, n - 1) + C(k - 1, n - 1);
    return memo[k][n];
}

int main()
{
    std::fill(&memo[0][0], &memo[0][0] + sizeof(memo) / sizeof(int), -1);
    cout << C(4, 6) << endl;

    return 0;
}